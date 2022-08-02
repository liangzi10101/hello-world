#include <iostream>
#include <string>
#include "tinyxml.h"

int main(int argc, char const* argv[]) {
    bool isXML = false;
    if (isXML) {
        TiXmlDocument xml_doc;
        // 添加XML声明
        xml_doc.LinkEndChild(new TiXmlDeclaration("1.0", "GBK", ""));
        // 添加根元素
        TiXmlElement* xml_html = new TiXmlElement("html");
        xml_doc.LinkEndChild(xml_html);

        // 嵌套子元素
        TiXmlElement* xml_body = new TiXmlElement("body");
        xml_html->LinkEndChild(xml_body);

        TiXmlElement* xml_h1 = new TiXmlElement("h1");
        xml_h1->LinkEndChild(new TiXmlText("My first SVG"));
        xml_body->LinkEndChild(xml_h1);

        TiXmlElement* xml_circle = new TiXmlElement("circle");
        xml_circle->SetAttribute("cx", "100");
        xml_circle->SetAttribute("cy", "50");
        xml_circle->SetAttribute("r", "40");
        xml_circle->SetAttribute("stroke", "black");
        xml_circle->SetAttribute("stroke-width", "2");
        xml_circle->SetAttribute("fill", "red");

        TiXmlElement* xml_svg = new TiXmlElement("svg");
        xml_svg->SetAttribute("xmlns", "http://www.w3.org/2000/svg");
        xml_svg->SetAttribute("version", "1.1");
        xml_svg->LinkEndChild(xml_circle);
        xml_body->LinkEndChild(xml_svg);

        // 保存到文件
        xml_doc.SaveFile("example.html");

        std::cout << "xml generate accomplished!\n";
    } else {  // svg
        TiXmlDocument xml_doc;

        TiXmlElement* xml_circle = new TiXmlElement("circle");
        xml_circle->SetAttribute("cx", "100");
        xml_circle->SetAttribute("cy", "50");
        xml_circle->SetAttribute("r", "40");
        xml_circle->SetAttribute("stroke", "black");
        xml_circle->SetAttribute("stroke-width", "2");
        xml_circle->SetAttribute("fill", "red");

        TiXmlElement* xml_svg = new TiXmlElement("svg");
        xml_svg->SetAttribute("xmlns", "http://www.w3.org/2000/svg");
        xml_svg->SetAttribute("version", "1.1");
        xml_svg->LinkEndChild(xml_circle);
        xml_doc.LinkEndChild(xml_svg);

        // 保存到文件
        xml_doc.SaveFile("example.svg");
        std::string svgStr;
        xml_doc.SaveSvgToStr(svgStr);

        std::cout << "svg generate accomplished!\n" << svgStr << std::endl;
    }

    return 0;
}