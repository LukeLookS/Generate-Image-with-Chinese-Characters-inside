/////////////////////////////////////////////////////////////////////
// CvxText.h - Set the text format						           //
// ver 1.1                                                         //
//-----------------------------------------------------------------//
//  Language:      Visual C++ 2017, Community                      //
//  Platform:      Dell XPS 13, Linux Ubuntu16.04                  //
//  Application:   Package for setting input text format           //
//  Author:        Mengjie Shi						               //
//                 (315)-949-8587	smjusing@gmail.com             //
/////////////////////////////////////////////////////////////////////
/*
*  Package Operations:
*  ===================
*  Output the image generate by opencv and use CvxText class to
*  adjust the font of text
*/

#ifndef OPENCV_CVX_TEXT_HPP_
#define OPENCV_CVX_TEXT_HPP_

#include <ft2build.h>
#include FT_FREETYPE_H

#include <opencv2/opencv.hpp>

class CvxText {
public:
    CvxText(const char* freeType); //装载字库文件
    virtual ~CvxText();
public:
	// 获得字体
    void getFont(int* type, cv::Scalar* size=nullptr, bool* underline=nullptr, float* diaphaneity=nullptr); 
	// 设置字体
    void setFont(int* type, cv::Scalar* size=nullptr, bool* underline=nullptr, float* diaphaneity=nullptr);
	// 恢复原始字体
    void restoreFont();
	// 输出字体
    int putText(cv::Mat& img, char* text, cv::Point pos);
	// 输出汉字 非RGB
    int putText(cv::Mat& img, const wchar_t* text, cv::Point pos);
	// 输出汉字 RGB
    int putText(cv::Mat& img, const char* text, cv::Point pos, cv::Scalar color);
    int putText(cv::Mat& img, const wchar_t* text, cv::Point pos, cv::Scalar color);

private:
    // 禁止copy
    CvxText& operator=(const CvxText&);
    // 输出当前字符, 更新m_pos位置
    void putWChar(cv::Mat& img, wchar_t wc, cv::Point& pos, cv::Scalar color);
    FT_Library   m_library;   // 字库
    FT_Face      m_face;      // 字体
    // 默认的字体输出参数
    int         m_fontType;
    cv::Scalar   m_fontSize;
    bool      m_fontUnderline;
    float      m_fontDiaphaneity;
};

#endif // OPENCV_CVX_TEXT_HPP_
