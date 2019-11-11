//
//  HandleManagerFilterModel.h
//  NCGPUImageDemo
//
//  Created by lishengfeng on 2019/11/11.
//  Copyright © 2019 Nicolas. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef enum {
    //基本功能
    FilterType_SATURATION,//饱和度
    FilterType_CONTRAST,//对比度
    FilterType_OPACITY,//透明度
    FilterType_WHITEBALANCE,//饱和度
    FilterType_BRIGHTNESS,//亮度（美白）
    FilterType_EXPOSURE,//曝光
    //色彩
    FilterType_RGB,//RGB
    FilterType_LEVELS,//色阶
    FilterType_HUE,//单色
    FilterType_MONOCHROME,//色阶
    FilterType_GAMMA,//灰度
    FilterType_TONECURVE,//曲线
    FilterType_HIGHLIGHTSHADOW,//高光阴影
    FilterType_HAZE,//去雾
    FilterType_COLORINVERT,//反色(反相)
    FilterType_GRAYSCALE,//黑白
    //图像分析
    FilterType_HISTOGRAM,//直方图
    FilterType_HISTOGRAM_EQUALIZATION,//直方图均衡过滤
    FilterType_AVERAGECOLOR,//平均颜色
    FilterType_LUMINOSITY,//平均亮度
    FilterType_THRESHOLD,//亮度阈值
    FilterType_ADAPTIVETHRESHOLD,//自适应阈值
    FilterType_AVERAGELUMINANCETHRESHOLD,//平均亮度阈值
    //色彩滤镜
    FilterType_FALSECOLOR,//颜色混合
    FilterType_CHROMAKEYNONBLEND,//色度key(//两幅图像叠加保留一幅图像指定色度)
    //(下面三滤镜 需要使用外部图片资源)
    FilterType_MISSETIKATE,//Miss Etikate滤镜
    FilterType_SOFTELEGANCE,//颜色重映射滤镜
    FilterType_AMATORKA,//Amatorka滤镜
    FilterType_SEPIA,//棕褐色
    
    //图像处理
    //1常见处理
    FilterType_SHARPEN,//锐化
    FilterType_UNSHARPMASK,//USM锐化(锐化边缘)
    FilterType_CROP,//裁剪
    FilterType_TRANSFORM,//2d空间图像变形
    FilterType_TRANSFORM3D,//3d空间图像变形
    //2边缘及特征检测
    FilterType_SOBELEDGEDETECTION,//sobel边缘检测(以白色突出显示)
    FilterType_PREWITTEDGEDETECTION,//prewitt边缘检测
    FilterType_CANNYEDGEDETECTION,//canny  边缘检测
    FilterType_THRESHOLDEDGEDETECTION,//Threshold 边缘检测（应用阈值，而不是赋予渐变强度值）
    FilterType_XYGRADIENT,//XYDerivative边缘检测（画面以蓝色为主，绿色为边缘，带彩色）
    FilterType_HARRISCORNERDETECTION,//哈里斯角特征检测
    FilterType_NOBLECORNERDETECTION,//Noble特征检测
    FilterType_SHITOMASIFEATUREDETECTION,//Shi-Tomasi特征检测
    FilterType_HOUGHTRANSFORMLINEDETECTOR,//线条检测
    //3 模糊 （减少图像噪声以及降低细节层次，达到平滑的效果）
    //可以应用于整幅图像，或者局部区域，边缘，运动方向 美颜处理中皮肤光滑的处理就采用了模糊滤镜
    FilterType_GAUSSIAN,//高斯模糊
    FilterType_MEDIAN,//3x3模糊(取三个颜色分量的中值)
    FilterType_BILATERAL,//双边模糊(保留锐利边缘的同时模糊相似的颜色值)
    FilterType_MOTIONBLUR,//定向运动模糊
    FilterType_ZOOMBLUR,//定向运动模糊
    FilterType_BOXBLUR,//盒状模糊(方形)
    FilterType_GAUSSIAN_SELECTIVE,//保证圆形区域内清晰的高斯模糊
    FilterType_GAUSSIAN_POSITION,//只在圆形区域内高斯模糊
    FilterType_IOSBLUR,//毛玻璃效果
    FilterType_OPENING,//过滤出较小的明亮区域
    FilterType_CLOSING,//过滤掉较小的黑暗区域
    //(边缘处理 ：主要对图像边缘像素做矩形化处理，整个图像呈现轮廓块状模糊)
    FilterType_DILATION,//扩张边缘
    FilterType_EROSION,//侵蚀边缘
    //4 运算
    FilterType_MOTIONDETECTOR,//运动检测，基于高通滤波器
    FilterType_LOWPASS,//低通滤波器
    FilterType_HIGHPASS,//高通滤波器
    FilterType_CONVOLUTION,//3x3卷积
    FilterType_LAPLACIAN,//拉普拉斯矩阵变换
    //混合模式
    FilterType_AlphaBlend,//alpha混合
    FilterType_MASK,//使用另一幅图像遮罩当前图像
    FilterType_DISSOLVE,//溶解
    FilterType_CHROMAKEY,//(green)色度键混合
    FilterType_SCREENBLEND,//屏幕混合
    FilterType_COLORDODGE,//色彩加深混合
    FilterType_LINEARBURN,//线性混合
    FilterType_ADD,//添加混合
    FilterType_DIVIDE,//分割混合
    FilterType_MULTIPLY,//乘法混合
    FilterType_OVERLAY,//叠加混合
    FilterType_LIGHTEN,//减淡混合
    FilterType_DARKE,//加深混合
    FilterType_EXCLUSIONBLEND,//排除混合
    FilterType_DIFFERENCEBLEND,//差异混合
    FilterType_SUBTRACTBLEND,//差值混合
    FilterType_HARDLIGHTBLEND,//强光混合
    FilterType_SOFTLIGHTBLEND,//柔光混合
    FilterType_COLORBLEND,//颜色混合
    FilterType_HUEBLEND,//色调混合
    FilterType_SATURATIONBLEND,//饱和度混合
    FilterType_LUMINOSITYBLEN,//亮度混合
    FilterType_NORMALBLEND,//正常混合
    FilterType_POISSONBLEND,//泊松混合
    //混视觉特效
    FilterType_IXELLATE,//像素图效果,马赛克
    FilterType_POLARPIXELLATE,//使用极坐标代替笛卡尔坐标的像素图效果
    FilterType_PIXELLATE_POSITION,//局部马赛克效果
    FilterType_POLKADOT,//分解图像为常规网格中的彩色点
    FilterType_HALFTONE,//半色调效果，如新闻打印
    FilterType_CROSSHATCH,//黑白交叉影线效果
    FilterType_SKETCH,//素描效果（使用Sobel边缘检测滤镜，颜色反转）
    FilterType_THRESHOLDSKETCH,//阈值素描，有噪点
    FilterType_TOON,//卡通效果(使用Sobel边缘检测在对象周围放置黑色边框，然后量化图像中存在的颜色)
    FilterType_SMOOTHTOON,//图像平滑
    FilterType_TILTSHIFT,//条纹模糊
    FilterType_CGA,//CGA色彩空间效果(模拟CGA色彩空间效果，形成黑、浅蓝、紫色块的画面)
    FilterType_EMBOSS,//浮雕效果
    FilterType_POSTERIZE,//类似卡通的简单阴影图像
    FilterType_SWIRL,//旋涡效果
    FilterType_BULGE,//凸起效果， 鱼眼
    FilterType_SPHEREREFRACTION,//玻璃球折射，图像反转
    FilterType_GLASSSPHERE,//图像不反转，玻璃边缘有一点结霜
    FilterType_PINCH,//收缩 ，凹面镜
    FilterType_STRETCH,//拉伸效果，哈哈镜
    FilterType_PERLINNOISE,//柏林噪点，花边噪点
    FilterType_VORONOI,//生成Voronoi映射
    FilterType_MOSAIC,//黑白马赛克效果
    FilterType_LOCALBINARYPATTERN,//黑白化，有噪点
    FilterType_VIGNETTE,//晕影，暗角
    FilterType_KUWAHARA,//滤波器水粉画效果
    FilterType_KUWAHARARADIUS3,//优化版三像素半径
    //其他
    FilterType_BUFFER,//buffer(未知)
    FilterType_UIELEMENT,//叠加(将APPView中的UI控件使用Alpha 混合滤镜叠加到在图像上)
    FilterType_CUSTOM,//用户自定义滤镜（.fsh文件）
    FilterType_FILECONFIG,//外部配置文件(plist文件中包括多个滤镜)
    FilterType_FILTERGROUP,//多个滤镜
    FilterType_FACES,//人脸检测
    
}GPUImageFilterType;

@interface HandleManagerFilterModel : NSObject

@end

NS_ASSUME_NONNULL_END
