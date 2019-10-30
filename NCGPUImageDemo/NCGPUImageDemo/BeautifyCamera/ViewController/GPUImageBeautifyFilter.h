//
//  GPUImageBeautifyFilter.h
//  NCGPUImageDemo
//
//  Created by lishengfeng on 2019/10/30.
//  Copyright © 2019 Nicolas. All rights reserved.
//

#import "GPUImageFilterGroup.h"
#import <GPUImage/GPUImage.h>

@class GPUImageCombinationFilter;
NS_ASSUME_NONNULL_BEGIN

@interface GPUImageBeautifyFilter : GPUImageFilterGroup{
    GPUImageBilateralFilter *bilateralFilter;
    GPUImageCannyEdgeDetectionFilter *cannyEdgeFilter;
    GPUImageCombinationFilter *combinationFilter;
    GPUImageHSBFilter *hsbFilter;
}

@end

NS_ASSUME_NONNULL_END
