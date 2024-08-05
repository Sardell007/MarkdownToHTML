/**
 * @file Unit Test Module to test written code
 * @author Chilukamari Shiva Sai Krishna (mcs232499@cse.iitd.ac.in)
 * @brief 
 * @version 0.1
 * @date 2023-08-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <fstream>
#include <gtest/gtest.h>
#include "util.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <cstdio>
#include "parsor.tab.h"

extern "C" FILE *yyin;
extern "C" int yylex();
int yyparse(FILE* fp);

#ifdef __cplusplus
}
#endif

TEST(EMPHASIS, BOLD)
{
	yyin = fopen(emphasis_boldmdfile,"r");
	FILE* fout = fopen(emphasis_boldhtmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(emphasis_boldhtmlgtfile);
	std::ifstream pdFile(emphasis_boldhtmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(EMPHASIS, BOLDITALIC)
{
	yyin = fopen(emphasis_bolditalicmdfile,"r");
	FILE* fout = fopen(emphasis_bolditalichtmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(emphasis_bolditalichtmlgtfile);
	std::ifstream pdFile(emphasis_bolditalichtmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(EMPHASIS, ITALIC)
{
	yyin = fopen(emphasis_italicmdfile,"r");
	FILE* fout = fopen(emphasis_italichtmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(emphasis_italichtmlgtfile);
	std::ifstream pdFile(emphasis_italichtmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(HEADER, HEADER1)
{
	yyin = fopen(header_header1mdfile,"r");
	FILE* fout = fopen(header_header1htmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(header_header1htmlgtfile);
	std::ifstream pdFile(header_header1htmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(HEADER, HEADER2)
{
	yyin = fopen(header_header2mdfile,"r");
	FILE* fout = fopen(header_header2htmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(header_header2htmlgtfile);
	std::ifstream pdFile(header_header2htmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(HEADER, HEADER3)
{
	yyin = fopen(header_header3mdfile,"r");
	FILE* fout = fopen(header_header3htmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(header_header3htmlgtfile);
	std::ifstream pdFile(header_header3htmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(HEADER, HEADER4)
{
	yyin = fopen(header_header4mdfile,"r");
	FILE* fout = fopen(header_header4htmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(header_header4htmlgtfile);
	std::ifstream pdFile(header_header4htmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(HEADER, HEADER5)
{
	yyin = fopen(header_header5mdfile,"r");
	FILE* fout = fopen(header_header5htmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(header_header5htmlgtfile);
	std::ifstream pdFile(header_header5htmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(HEADER, HEADER6)
{
	yyin = fopen(header_header6mdfile,"r");
	FILE* fout = fopen(header_header6htmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(header_header6htmlgtfile);
	std::ifstream pdFile(header_header6htmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(HYPERLINK, NOTITLE)
{
	yyin = fopen(hyperlink_notitlemdfile,"r");
	FILE* fout = fopen(hyperlink_notitlehtmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(hyperlink_notitlehtmlgtfile);
	std::ifstream pdFile(hyperlink_notitlehtmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(HYPERLINK, NOTITLEIMAGE)
{
	yyin = fopen(hyperlink_notitleimagemdfile,"r");
	FILE* fout = fopen(hyperlink_notitleimagehtmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(hyperlink_notitleimagehtmlgtfile);
	std::ifstream pdFile(hyperlink_notitleimagehtmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(HYPERLINK, TITLE)
{
	yyin = fopen(hyperlink_titlemdfile,"r");
	FILE* fout = fopen(hyperlink_titlehtmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(hyperlink_titlehtmlgtfile);
	std::ifstream pdFile(hyperlink_titlehtmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(HYPERLINK, TITLEIMAGE)
{
	yyin = fopen(hyperlink_titleimagemdfile,"r");
	FILE* fout = fopen(hyperlink_titleimagehtmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(hyperlink_titleimagehtmlgtfile);
	std::ifstream pdFile(hyperlink_titleimagehtmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(IMAGE, NOTITLE)
{
	yyin = fopen(image_notitlemdfile,"r");
	FILE* fout = fopen(image_notitlehtmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(image_notitlehtmlgtfile);
	std::ifstream pdFile(image_notitlehtmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(IMAGE, TITLE)
{
	yyin = fopen(image_titlemdfile,"r");
	FILE* fout = fopen(image_titlehtmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(image_titlehtmlgtfile);
	std::ifstream pdFile(image_titlehtmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(ORDEREDLIIST, START1)
{
	yyin = fopen(orderedliist_start1mdfile,"r");
	FILE* fout = fopen(orderedliist_start1htmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(orderedliist_start1htmlgtfile);
	std::ifstream pdFile(orderedliist_start1htmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(ORDEREDLIST, SINGLEELEM)
{
	yyin = fopen(orderedlist_singleelemmdfile,"r");
	FILE* fout = fopen(orderedlist_singleelemhtmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(orderedlist_singleelemhtmlgtfile);
	std::ifstream pdFile(orderedlist_singleelemhtmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(ORDEREDLIST, START100)
{
	yyin = fopen(orderedlist_start100mdfile,"r");
	FILE* fout = fopen(orderedlist_start100htmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(orderedlist_start100htmlgtfile);
	std::ifstream pdFile(orderedlist_start100htmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(ORDEREDLIST, START1UNORDER)
{
	yyin = fopen(orderedlist_start1unordermdfile,"r");
	FILE* fout = fopen(orderedlist_start1unorderhtmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(orderedlist_start1unorderhtmlgtfile);
	std::ifstream pdFile(orderedlist_start1unorderhtmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(PARA, DOUBLELINE)
{
	yyin = fopen(para_doublelinemdfile,"r");
	FILE* fout = fopen(para_doublelinehtmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(para_doublelinehtmlgtfile);
	std::ifstream pdFile(para_doublelinehtmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(PARA, LINEBREAK)
{
	yyin = fopen(para_linebreakmdfile,"r");
	FILE* fout = fopen(para_linebreakhtmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(para_linebreakhtmlgtfile);
	std::ifstream pdFile(para_linebreakhtmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(PARA, SAMELINE)
{
	yyin = fopen(para_samelinemdfile,"r");
	FILE* fout = fopen(para_samelinehtmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(para_samelinehtmlgtfile);
	std::ifstream pdFile(para_samelinehtmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(PARA, SINGLE)
{
	yyin = fopen(para_singlemdfile,"r");
	FILE* fout = fopen(para_singlehtmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(para_singlehtmlgtfile);
	std::ifstream pdFile(para_singlehtmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(TABLE, MULTIROWCOLOUM)
{
	yyin = fopen(table_multirowcoloummdfile,"r");
	FILE* fout = fopen(table_multirowcoloumhtmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(table_multirowcoloumhtmlgtfile);
	std::ifstream pdFile(table_multirowcoloumhtmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(TABLE, SINGLECOLUMN)
{
	yyin = fopen(table_singlecolumnmdfile,"r");
	FILE* fout = fopen(table_singlecolumnhtmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(table_singlecolumnhtmlgtfile);
	std::ifstream pdFile(table_singlecolumnhtmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(TABLE, SINGLEROW)
{
	yyin = fopen(table_singlerowmdfile,"r");
	FILE* fout = fopen(table_singlerowhtmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(table_singlerowhtmlgtfile);
	std::ifstream pdFile(table_singlerowhtmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(UNORDEREDLIST, MULTIELEM)
{
	yyin = fopen(unorderedlist_multielemmdfile,"r");
	FILE* fout = fopen(unorderedlist_multielemhtmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(unorderedlist_multielemhtmlgtfile);
	std::ifstream pdFile(unorderedlist_multielemhtmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(UNORDEREDLIST, MULTILIST)
{
	yyin = fopen(unorderedlist_multilistmdfile,"r");
	FILE* fout = fopen(unorderedlist_multilisthtmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(unorderedlist_multilisthtmlgtfile);
	std::ifstream pdFile(unorderedlist_multilisthtmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}

TEST(UNORDEREDLIST, SINGLEELEM)
{
	yyin = fopen(unorderedlist_singleelemmdfile,"r");
	FILE* fout = fopen(unorderedlist_singleelemhtmlgtfile, "w");
	yyparse(fout);
	fclose(fout);
	std::ifstream gtFile(unorderedlist_singleelemhtmlgtfile);
	std::ifstream pdFile(unorderedlist_singleelemhtmlpdfile);
	std::string gtString((std::istreambuf_iterator<char>(gtFile)), std::istreambuf_iterator<char>());
	std::string pdString((std::istreambuf_iterator<char>(pdFile)), std::istreambuf_iterator<char>());
	EXPECT_EQ(gtString,pdString);
}
int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
