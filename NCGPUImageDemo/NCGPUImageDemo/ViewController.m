//
//  ViewController.m
//  NCGPUImageDemo
//
//  Created by lishengfeng on 2019/10/30.
//  Copyright © 2019 Nicolas. All rights reserved.
//

#import "ViewController.h"
#import "BeautifyCameraViewController.h"
#import "BeautifyImageViewController.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    self.title = @"NCGPUImageDemo";
    
    UIButton *button = [[UIButton alloc]initWithFrame:CGRectMake((self.view.frame.size.width-100)*0.5, 200, 100, 60)];
    button.tag = 100;
    [button setTitle:@"图片处理" forState:UIControlStateNormal];
    [button setBackgroundColor:[UIColor orangeColor]];
    [button setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [button addTarget:self action:@selector(butonAction:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
    button.layer.cornerRadius = 10.0;
    
    UIButton *button2 = [[UIButton alloc]initWithFrame:CGRectMake((self.view.frame.size.width-100)*0.5, 300, 100, 60)];
    button2.tag = 200;
    [button2 setTitle:@"美颜相机" forState:UIControlStateNormal];
    [button2 setBackgroundColor:[UIColor orangeColor]];
    [button2 setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [button2 addTarget:self action:@selector(butonAction:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button2];
    button2.layer.cornerRadius = 10.0;
    
    
}

- (void)butonAction:(UIButton *)button{
    if (button.tag == 100) {
        BeautifyImageViewController *bivc = [[BeautifyImageViewController alloc]init];
        [self.navigationController pushViewController:bivc animated:true];
    }else{
       BeautifyCameraViewController *bcvc = [[BeautifyCameraViewController alloc]init];
        [self.navigationController pushViewController:bcvc animated:true];
    }
}
@end
