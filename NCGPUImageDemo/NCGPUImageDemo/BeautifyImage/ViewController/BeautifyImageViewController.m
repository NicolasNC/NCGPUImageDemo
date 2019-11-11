//
//  BeautifyImageViewController.m
//  NCGPUImageDemo
//
//  Created by lishengfeng on 2019/10/30.
//  Copyright © 2019 Nicolas. All rights reserved.
//

#import "BeautifyImageViewController.h"
#import <GPUImage/GPUImage.h>

@interface BeautifyImageViewController ()
@property(nonatomic,strong)UIImage *image;
@property(nonatomic,strong)UIImageView *originImageView;
@property(nonatomic,strong)UIImageView *resultImageView;
@end

@implementation BeautifyImageViewController
- (void)writePlist{
   
}
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    self.title = @"图片处理";
    
    
    
    UIImage *image = [UIImage imageNamed:@"origin.jpg"];
    self.image = image;
    self.originImageView.image = image;
    
     //对比度 0  1  4
    GPUImageContrastFilter *filter = [[GPUImageContrastFilter alloc]init];
    filter.contrast = 1.5;
    [filter forceProcessingAtSize:_image.size];
    [self updataImage:filter];

    
    //饱和度 0 1 2.0
    GPUImageSaturationFilter *filter1 = [[GPUImageSaturationFilter alloc]init];
    filter1.saturation = 1.5;
    [filter1 forceProcessingAtSize:_image.size];
    [self updataImage:filter1];
    
    //曝光度 -10 0 10
    GPUImageExposureFilter *filter2 = [[GPUImageExposureFilter alloc] init];
    filter2.exposure = 8;
    [filter2 forceProcessingAtSize:_image.size];
    [self updataImage:filter2];
    
    
    
    
    //色温(白平衡)
    GPUImageWhiteBalanceFilter *filter3 = [[GPUImageWhiteBalanceFilter alloc] init];
    //开氏度 为单位
    filter3.temperature = 0.5;
    //补偿
    filter3.tint = 0.0;
    //设置要渲染的区域
    [filter3 forceProcessingAtSize:_image.size];
    [self updataImage:filter3];
    
    
}
- (void)updataImage:(GPUImageFilter *)filter{
    //获取 GPU 图片
    GPUImagePicture *pic = [[GPUImagePicture alloc]initWithImage:_image];
    //添加滤镜
    [pic addTarget:filter];
    //开始渲染
    [pic processImage];
    //(需要调用一下? why?)
    [filter useNextFrameForImageCapture];
    //获取渲染后的图片
    UIImage *newImage = [filter imageFromCurrentFramebuffer];
     
    self.resultImageView.image = newImage;
}
- (UIImageView *)originImageView{
    UIImageView *imageView = [self.view viewWithTag:1001];
    if (!imageView) {
        imageView = [[UIImageView alloc]initWithFrame:CGRectMake(0, 100, self.view.frame.size.width*0.5, self.view.frame.size.height-100*2)];
        imageView.contentMode = UIViewContentModeScaleAspectFit;
        imageView.tag = 1001;
        [self.view addSubview:imageView];
    }
    return imageView;
}

- (UIImageView *)resultImageView{
    UIImageView *imageView = [self.view viewWithTag:1002];
    if (!imageView) {
        imageView = [[UIImageView alloc]initWithFrame:CGRectMake(self.view.frame.size.width*0.5, 100, self.view.frame.size.width*0.5, self.view.frame.size.height-100*2)];
        imageView.contentMode = UIViewContentModeScaleAspectFit;
        imageView.tag = 1002;
        [self.view addSubview:imageView];
    }
    return imageView;
}
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
