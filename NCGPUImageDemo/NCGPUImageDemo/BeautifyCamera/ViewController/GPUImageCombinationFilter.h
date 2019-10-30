//
//  GPUImageCombinationFilter.h
//  NCGPUImageDemo
//
//  Created by lishengfeng on 2019/10/30.
//  Copyright © 2019 Nicolas. All rights reserved.
//

#import "GPUImageThreeInputFilter.h"

NS_ASSUME_NONNULL_BEGIN

@interface GPUImageCombinationFilter : GPUImageThreeInputFilter
{
    GLint smoothDegreeUniform;
}

@property (nonatomic, assign) CGFloat intensity;
@end

NS_ASSUME_NONNULL_END
