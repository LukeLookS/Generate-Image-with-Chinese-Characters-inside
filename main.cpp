/////////////////////////////////////////////////////////////////////
// main.cpp - Output the result and meet the requirements          //
// ver 1.1                                                         //
//-----------------------------------------------------------------//
//  Language:      Visual C++ 2017, Community                      //
//  Platform:      Dell XPS 13, Linux Ubuntu16.04                  //
//  Application:   Package for coverting text to image             //
//  Author:        Mengjie Shi						               //
//                 (315)-949-8587	smjusing@gmail.com             //
/////////////////////////////////////////////////////////////////////
/*
*  Package Operations:
*  ===================
*  Output the image generate by opencv and use CvxText class to 
*  adjust the font of text
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "time.h"
#include "CvxText.h"

//中文字体格式转换
static int ToWchar(char* &src, wchar_t* &dest, const char *locale = "zh_CN.utf8")
{
    if (src == NULL) {
        dest = NULL;
        return 0;
    }

    // 根据环境变量设置locale
    setlocale(LC_CTYPE, locale);

    // 得到转化为需要的宽字符大小
    int w_size = mbstowcs(NULL, src, 0) + 1;

    // 非法字符检查
    if (w_size == 0) {
        dest = NULL;
        return -1;
    }

    dest = new wchar_t[w_size];
    if (!dest) {
        return -1;
    }

    int ret = mbstowcs(dest, src, strlen(src)+1);
    if (ret <= 0) {
        return -1;
    }
    return 0;
}

int main(int argc, char* argv[])
{

    char *names[3] = {"Sample\nText","中国","中國",};    // input string
    const char* fronttype[5] = {"calibri","msyh","simhei","times","timesi"};        //支持字体

    int w = 224;
    int h = 224; // 图片大小
    cv::Point pt = cv::Point(atoi(argv[1]), atoi(argv[2]));    // 字体起始位置

    int Fontsize = atoi(argv[3]);       // 32 字体大小
    int selectType = atoi(argv[4]);    //2;         //range(0,4)

    int selectstring = atoi(argv[5]);   //1     // range(0,2)   //和string type一样
    int stringType = atoi(argv[6]);     //1;         //字符串类型：中文为1 or 英文为0

    cv::Mat img = cv::Mat::zeros(w,h,CV_8UC3);
    if (!img.data || img.channels() != 3) {
        fprintf(stderr, "read image fail\n");
        return -1;
    }

    char tem[1024] = {0};
    sprintf(tem,"./putText/%s.ttf",fronttype[selectType]);       //  选择字体
    CvxText text(tem);
    cv::Scalar size1{ Fontsize, 0.5, 0.1, 0 };

    text.setFont(nullptr, &size1, nullptr, 0);
    char* str = names[selectstring];       // 输出的字符串

    cv::Scalar font_size_;
    text.getFont(0, &font_size_, NULL, NULL);


    /**/
    if(stringType==0)
    {
        // 输出英文
        std::string::size_type pos_begain = 0;
        std::string::size_type pos_end = pos_begain;
        int i = 0;
        std::string s = (std::string)str;
        //逐行叠加
        while( (pos_end = s.find('\n', pos_begain)) != std::string::npos )
        {
            std::string str_tmp = s.substr(pos_begain, pos_end - pos_begain);
            std::cout << str_tmp << std::endl;
            pos_begain = pos_end + 1;
            text.putText(img, str_tmp.c_str() , cv::Point(pt.x, pt.y  + i * font_size_.val[0]), cv::Scalar(0, 0, 255));
            i++;
        }
        //最后一行叠加字符
        std::string str_tmp = s.substr(pos_begain);
        text.putText(img, str_tmp.c_str() , cv::Point(pt.x, pt.y + i * font_size_.val[0]),cv::Scalar(0, 0, 255));

    }
    else if(stringType==1){
        // output 汉字
        wchar_t *w_str;
        ToWchar(str,w_str);     // 调整中文字体的宽度
        text.putText(img, w_str, pt, cv::Scalar(0, 0, 255));
    }

   // cv::imshow("demo", img);
    cv::imwrite("SAMPLE.JPG",img);
    //cv::waitKey(0);
    return 0;
}
