
# NMS

import numpy as np

def NMS(dets, thresh):

    #x1、y1、x2、y2、以及score赋值
    # （x1、y1）（x2、y2）为box的左上和右下角标
    x1 = dets[:, 0]
    y1 = dets[:, 1]
    x2 = dets[:, 2]
    y2 = dets[:, 3]
    scores = dets[:, 4]


    #每一个候选框的面积
    areas = (x2 - x1 + 1) * (y2 - y1 + 1)
    #order是按照score降序排序的，得到的是排序的本来的索引，不是排完序的原数组
    order = scores.argsort()[::-1]
    # ::-1表示逆序


    temp = []
    while order.size > 0:
        i = order[0]
        temp.append(i)
        #计算当前概率最大矩形框与其他矩形框的相交框的坐标
        # 由于numpy的broadcast机制，得到的是向量
        xx1 = np.maximum(x1[i], x1[order[1:]])
        yy1 = np.minimum(y1[i], y1[order[1:]])
        xx2 = np.minimum(x2[i], x2[order[1:]])
        yy2 = np.maximum(y2[i], y2[order[1:]])

        #计算相交框的面积,注意矩形框不相交时w或h算出来会是负数，需要用0代替
        w = np.maximum(0.0, xx2 - xx1 + 1)
        h = np.maximum(0.0, yy2 - yy1 + 1)
        inter = w * h
        #计算重叠度IoU
        ovr = inter / (areas[i] + areas[order[1:]] - inter)

        #找到重叠度不高于阈值的矩形框索引
        inds = np.where(ovr <= thresh)[0]
        #将order序列更新，由于前面得到的矩形框索引要比矩形框在原order序列中的索引小1，所以要把这个1加回来
        order = order[inds + 1]
    return temp

# IOU
import numpy as np


def iou(gtboxes, dtboxes):
    '''numpy version of calculating IoU between two set of 2D bboxes.

    Args:
        gtboxes (np.ndarray): Shape (B,4) of ..,  4 present [x1,y1,x2,y2]
        dtboxes,np.ndarray,shape:(N,4), 4 present [x1,y1,x2,y2].

    Returns:
        np.ndarray: Shape (B,N)  .
    '''
    gtboxes = gtboxes[:, np.
                      newaxis, :]  #converse gtboxes:(B,4) to gtboxes:(B,1,4)
    ixmin = np.maximum(gtboxes[:, :, 0], dtboxes[:, 0])
    iymin = np.maximum(gtboxes[:, :, 1], dtboxes[:, 1])
    ixmax = np.minimum(gtboxes[:, :, 2], dtboxes[:, 2])
    iymax = np.minimum(gtboxes[:, :, 3], dtboxes[:, 3])
    intersection = (ixmax - ixmin + 1) * (iymax - iymin + 1)
    union = (gtboxes[:,:,2]-gtboxes[:,:,0]+1)*(gtboxes[:,:,3]-gtboxes[:,:,1]+1)\
            +(dtboxes[:,2]-dtboxes[:,0]+1)*(dtboxes[:,3]-dtboxes[:,1]+1)-intersection
    return intersection / union


def kmeans(data, K):
    """
    data: input data
    K: category number
    """
    
    n,d = data.shape
    cate_list = np.zeros(n)
    
    # - random centroid
    centroid_list = np.random.randn(K,d)
    
    is_ok = False
    lr = 0.5
    while not is_ok:
        # for j in range(n):
        #     nearest_centeroid_index = None
        #     nearest_centeroid_distance = float('inf')
            
        #     for k in range(K):
        #         dist = np.linalg.norm(centroid_list[k] - data[j])
        #         if dist < nearest_centeroid_distance:
        #             nearest_centeroid_distance = dist
        #             nearest_centeroid_index = k
        #     cate_list[j] = nearest_centeroid_index

        classifications = np.argmin(((data[:, :, None] - centers.T[None, :, :])**2).sum(axis=1), axis=1)
        new_centers = np.array([data[classifications == j, :].mean(axis=0) for j in range(k)])
        
        # - update centroid_list
        last_centroid_list = centroid_list.copy()
        for j in range(K):
            new_centroid = np.mean(data[cate_list==j], axis=0)
            centroid_list[j] = centroid_list[j]*lr + new_centroid*(1-lr) 
        print('centroid_list=', centroid_list)
            
        # - visualize
        plt.scatter(data[:,0], data[:,1], c=cate_list)
        plt.plot(centroid_list[:,0], centroid_list[:,1], 'r+')
        plt.show()
        
        # - check if need more update
        diff = np.linalg.norm(np.linalg.norm(centroid_list-last_centroid_list, axis=0))
        print('diff=', diff)
        if diff < 0.1:
            is_ok = True


