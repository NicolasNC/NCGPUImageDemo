//
//  BeautifyImageManagerModel.h
//  NCGPUImageDemo
//
//  Created by lishengfeng on 2019/10/30.
//  Copyright © 2019 Nicolas. All rights reserved.
//

#import "NCModel.h"

NS_ASSUME_NONNULL_BEGIN
@interface BeautifyItemModel : NCModel
@property (nonatomic) float min;
@property (nonatomic) float normal;
@property (nonatomic) float max;
@end
@interface BeautifyImageManagerModel : NCModel
@property (nonatomic) float contrast;
@end

NS_ASSUME_NONNULL_END
