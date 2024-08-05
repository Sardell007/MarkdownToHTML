/**
 * @file Node.hpp
 * @author Chilukamari Shiva Sai Krishna (mcs232499@cse.iitd.ac.in)
 * @brief Module for AST Nodes and it's funtionalities
 * @version 0.1
 * @date 2023-08-27
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef __NODE__
#define __NODE__

#include <string>
#include <vector>
#include <map>
#include "log.h"

/**
 * @brief Tags for Markdown AST
 *
 */
enum M_Tag
{
    M_NONE = 0,
    M_HEAD,
    M_PARA,
    M_ORD_LIST,
    M_ORD_LIST_ITEM,
    M_UNORDER_LIST,
    M_UNORDER_LIST_ITEM,
    M_TABLE,
    M_TABLE_ELEM,
    M_TEXT,
    M_DOC,
    M_LINE,
    M_TSU,
    M_TSUIH,
    M_ORD_LIST_START,
    M_IMG,
    M_ALTTEXT,
    M_IMGPATH,
    M_TITLE,
    M_TABLE_SINGLE,
    M_TABLE_LR_ENTRY,
    M_TABLE_R_ENTRY,
    M_TABLE_RW_ENTRY,
    M_TABLE_ENTRY,
    M_TABLE_HORI,
    M_HYPERLINK,
    M_TE2S,
    M_ST
};

/** @struct MNode
 *  @brief Nodes of AST for Markdown file
 *
 */
struct MNode
{
    /**
     * @brief M_Tag to identify type of MNode in tree
     *
     */
    M_Tag tag;

    /**
     * @name Data stored inside the nodes
     */
    /*@{*/
    int num;          /**< Variable to store integer data */
    char sym;         /**< Variable to store char data */
    std::string text; /**< Variable to store string data */
    /*@}*/

    bool visit;                           /**< Boolean to mark visited while traversing the tree */
    std::vector<struct MNode *> children; /** Vector of MNodes of children of the MNode */

    /**
     * @brief Construct a new MNode object
     *
     * @param _tag
     */
    MNode(M_Tag _tag = M_NONE) : tag{_tag}, visit{false} {}

    /**
     * @brief Helper funtion to add child
     *
     * @param n Child MNode to be added
     */
    void addChild(struct MNode *n)
    {
        children.push_back(n);
    }
};

/**
 * @brief Create a MNode object
 *
 * @param _tag MTag specifying the type of MNode
 * @param list List of child objects of the MNode
 * @param num Integer data of MNode
 * @param sym Character data of MNode
 * @param text String data of MNode
 * @return struct MNode* Pointer to the created MNode
 */
struct MNode *createMNode(M_Tag _tag = M_NONE, std::initializer_list<struct MNode *> list = {}, int num = -1, int sym = '\n', std::string text = "")
{
    struct MNode *n = new struct MNode(_tag);
    for (struct MNode *nc : list)
    {
        n->addChild(nc);
    }
    n->num = num;
    n->sym = sym;
    n->text = text;
    return n;
}

/**
 * @brief Mapping between MTag and string for debug
 *
 */
std::map<int, std::string> enumMName = {
    {M_NONE, "M_NONE"},
    {M_HEAD, "M_HEAD"},
    {M_PARA, "M_PARA"},
    {M_ORD_LIST, "M_ORD_LIST"},
    {M_ORD_LIST_ITEM, "M_ORD_LIST_ITEM"},
    {M_UNORDER_LIST, "M_UNORDER_LIST"},
    {M_UNORDER_LIST_ITEM, "M_UNORDER_LIST_ITEM"},
    {M_TABLE, "M_TABLE"},
    {M_TABLE_ELEM, "M_TABLE_ELEM"},
    {M_TEXT, "M_TEXT"},
    {M_DOC, "M_DOC"},
    {M_LINE, "M_LINE"},
    {M_TSU, "M_TSU"},
    {M_TSUIH, "M_TSUIH"},
    {M_ORD_LIST_START, "M_ORD_LIST_START"},
    {M_IMG, "M_IMG"},
    {M_ALTTEXT, "M_ALTTEXT"},
    {M_IMGPATH, "M_IMGPATH"},
    {M_TITLE, "M_TITLE"},
    {M_TABLE_SINGLE, "M_TABLE_SINGLE"},
    {M_TABLE_LR_ENTRY, "M_TABLE_LR_ENTRY"},
    {M_TABLE_R_ENTRY, "M_TABLE_R_ENTRY"},
    {M_TABLE_RW_ENTRY, "M_TABLE_RW_ENTRY"},
    {M_TABLE_ENTRY, "M_TABLE_ENTRY"},
    {M_TABLE_HORI, "M_TABLE_HORI"},
    {M_HYPERLINK, "M_HYPERLINK"},
    {M_TE2S, "M_TE2S"},
    {M_ST, "M_ST"},
};

/**
 * @brief Tags for HTML AST
 *
 */
enum H_Tag
{
    H_NONE = 0,
    H_HEAD,
    H_PARA,
    H_ORD_LIST,
    H_ORD_LIST_ITEM,
    H_UNORDER_LIST,
    H_UNORDER_LIST_ITEM,
    H_TABLE,
    H_TABLE_SINGLE,
    H_TABLE_HEAD,
    H_TABLE_ELEM,
    H_TEXT,
    H_IMG,
    H_ALTTEXT,
    H_IMGPATH,
    H_TITLE,
    H_HYPERLINK,
    H_ENDLINE,
    H_DOC,
    H_TEXT_A,
    H_TABLE_HEAD_S
};

/**
 * @brief Mapping between HTag and string for debug
 *
 */
std::map<int, std::string> enumHName = {
    {H_NONE, "H_NONE"},
    {H_HEAD, "H_HEAD"},
    {H_PARA, "H_PARA"},
    {H_ORD_LIST, "H_ORD_LIST"},
    {H_ORD_LIST_ITEM, "H_ORD_LIST_ITEM"},
    {H_UNORDER_LIST, "H_UNORDER_LIST"},
    {H_UNORDER_LIST_ITEM, "H_UNORDER_LIST_ITEM"},
    {H_TABLE, "H_TABLE"},
    {H_TABLE_SINGLE, "H_TABLE_SINGLE"},
    {H_TABLE_HEAD, "H_TABLE_HEAD"},
    {H_TABLE_ELEM, "H_TABLE_ELEM"},
    {H_TEXT, "H_TEXT"},
    {H_IMG, "H_IMG"},
    {H_ALTTEXT, "H_ALTTEXT"},
    {H_IMGPATH, "H_IMGPATH"},
    {H_TITLE, "H_TITLE"},
    {H_HYPERLINK, "H_HYPERLINK"},
    {H_ENDLINE, "H_ENDLINE"},
    {H_DOC, "H_DOC"},
    {H_TEXT_A, "H_TEXT_A"},
    {H_TABLE_HEAD_S, "H_TABLE_HEAD_S"}};

/** @struct HNode
 *  @brief Nodes of AST for HTML file
 *
 */
struct HNode
{
    /**
     * @brief H_Tag to identify type of HNode in tree
     *
     */
    H_Tag tag;

    /*@{*/
    std::string text;                     /**< Variable to store string data */
    std::vector<struct HNode *> children; /**< Vector of MNodes of children of the object*/
    struct HNode *parent;                 /**< Parent object in the tree*/
    /*@}*/

    /**
     * @brief Construct a new HNode object
     *
     * @param _tag
     */
    HNode(H_Tag _tag) : tag{_tag} {}

    /**
     * @brief Helper funtion to add child object
     *
     * @param n Child object to be added
     */
    void addChild(struct HNode *n)
    {
        children.push_back(n);
    }

    /**
     * @brief Set the Parent object
     *
     * @param p Parent object to be set
     */
    void setParent(struct HNode *p)
    {
        parent = p;
    }
};

/**
 * @brief Create a Node object
 *
 * @param _tag HTag specifying the type of MNode
 * @param list List of child obejcts of the MNode
 * @param text String data of MNode
 * @return struct HNode*
 */
struct HNode *createHNode(H_Tag _tag = H_NONE, std::initializer_list<struct HNode *> list = {}, std::string text = "")
{
    printf("Create %s: \n", enumMName[_tag].c_str());
    struct HNode *n = new struct HNode(_tag);
    for (struct HNode *nc : list)
    {
        n->addChild(nc);
        nc->setParent(n);
    }
    n->text = text;
    return n;
}

/**
 * @brief Travers the tree and print Parents and childrens tags in "NTree ParentTag: {Child1Tag, Child2Tag, ...}" format
 *
 * @param root MNode to start traversing
 */
void printTree(struct MNode *root)
{
    M_Tag t = root->tag;
    printf("MTree %s: {", enumMName[t].c_str());
    for (auto hnode : root->children)
    {
        printf("%s, ", enumMName[hnode->tag].c_str());
    }
    printf("}\n");
    for (auto hnode : root->children)
    {
        printTree(hnode);
    }
}

/**
 * @brief Convert Markdown AST to HTML AST
 *
 * @param root Root object of Markdown AST
 * @return struct HNode* Root object of HTML AST
 */
struct HNode *convert(struct MNode *root)
{
    M_Tag t = root->tag;
    DEBUG_LOG(printf("Tag: %s\n", enumMName[t].c_str());)
    switch (t)
    {
    case M_HEAD:
        DEBUG_LOG(printf("Line: %d\n", __LINE__);)
        return createHNode(H_HEAD, {convert(root->children.back())}, std::to_string(root->num));

    case M_ORD_LIST:
        DEBUG_LOG(printf("Line: %d\n", __LINE__);)
        if (root->children.size() == 1)
        {
            return createHNode(H_ORD_LIST, {convert(root->children.back())});
        }
        else
        {
            return createHNode(H_ORD_LIST, {convert(root->children.front()), convert(root->children.back())});
        }

    case M_ORD_LIST_ITEM:
        DEBUG_LOG(printf("Line: %d\n", __LINE__);)
        if (root->children.size() == 1)
        {
            return createHNode(H_ORD_LIST_ITEM, {convert(root->children.back())});
        }
        else
        {
            return createHNode(H_ORD_LIST_ITEM, {convert(root->children.front()), convert(root->children.back())});
        }

    case M_UNORDER_LIST:
        DEBUG_LOG(printf("Line: %d\n", __LINE__);)
        if (root->children.size() == 1)
        {
            return createHNode(H_UNORDER_LIST, {convert(root->children.back())});
        }
        else
        {
            if (root->children.front()->tag != root->children.back()->tag)
            {
                return createHNode(H_UNORDER_LIST, {convert(root->children.front()), convert(root->children.back())});
            }
            else
            {
                return createHNode(H_UNORDER_LIST, {convert(root->children.front()), createHNode(H_UNORDER_LIST, {convert(root->children.back())})});
            }
        }

    case M_UNORDER_LIST_ITEM:
        DEBUG_LOG(printf("Line: %d\n", __LINE__);)
        return createHNode(H_UNORDER_LIST_ITEM, {convert(root->children.back())});

    case M_IMG:
        DEBUG_LOG(printf("Line: %d\n", __LINE__);)
        return createHNode(H_IMG, {convert(root->children.front()), convert(root->children.back())});

    case M_ALTTEXT:
        DEBUG_LOG(printf("Line: %d\n", __LINE__);)
        return createHNode(H_ALTTEXT, {createHNode(H_TEXT, {}, root->children.front()->text)});

    case M_IMGPATH:
        DEBUG_LOG(printf("Line: %d\n", __LINE__);)
        if (root->children.size() == 0)
        {
            return createHNode(H_IMGPATH, {createHNode(H_TEXT, {}, root->text)});
        }
        else
        {
            return createHNode(H_IMGPATH, {createHNode(H_TEXT, {}, root->children.front()->text), convert(root->children.back())});
        }

    case M_HYPERLINK:
        DEBUG_LOG(printf("Line: %d\n", __LINE__);)
        if (root->children.back()->children.size() == 0)
        {
            return createHNode(H_HYPERLINK, {convert(root->children.front()), createHNode(H_TEXT, {}, root->children.back()->text)});
        }
        else
        {
            return createHNode(H_HYPERLINK, {convert(root->children.front()), createHNode(H_TEXT, {}, root->children.back()->children.front()->text), convert(root->children.back()->children.back())});
        }

    case M_TABLE:
        DEBUG_LOG(printf("Line: %d\n", __LINE__);)
        return createHNode(H_TABLE, {convert(root->children.front()), convert(root->children.back())});

    case M_TABLE_SINGLE:
        DEBUG_LOG(printf("Line: %d\n", __LINE__);)
        if (root->children.size() > 1)
        {
            return createHNode(H_TABLE_SINGLE, {convert(root->children.front()), convert(root->children.back())});
        }
        else
        {
            if (root->children.front()->children.size() == 1)
            {
                return createHNode(H_TABLE_SINGLE, {convert(root->children.back()->children.back())});
            }
            else
            {
                return createHNode(H_TABLE_SINGLE, {convert(root->children.back()->children.front()), convert(root->children.back()->children.back())});
            }
        }

    case M_TABLE_RW_ENTRY:
        DEBUG_LOG(printf("Line: %d\n", __LINE__);)
        if (root->children.size() == 1)
        {
            return createHNode(H_TABLE_SINGLE, {convert(root->children.front())});
        }
        else
        {
            return createHNode(H_TABLE_SINGLE, {convert(root->children.front()), convert(root->children.back())});
        }

    case M_TABLE_ENTRY:
        DEBUG_LOG(printf("Line: %d\n", __LINE__);)
        if (root->children.size() == 1)
        {
            return createHNode(H_TABLE_ELEM, {convert(root->children.back())});
        }
        else
        {
            return createHNode(H_TABLE_ELEM, {convert(root->children.front()), convert(root->children.back())});
        }

    case M_TSU:
        DEBUG_LOG(printf("Line: %d\n", __LINE__);)
        return createHNode(H_TEXT, {}, root->text);

    case M_TEXT:
        DEBUG_LOG(printf("Line: %d\n", __LINE__);)
        if (root->children.size() == 1)
        {
            return convert(root->children.front());
        }
        else
        {
            return createHNode(H_TEXT_A, {convert(root->children.front()), convert(root->children.back())});
        }

    case M_PARA:
        DEBUG_LOG(printf("Line: %d\n", __LINE__);)
        return createHNode(H_PARA, {convert(root->children.back())});

    case M_LINE:
        DEBUG_LOG(printf("Line: %d\n", __LINE__);)
        if (root->children.size() != 0)
        {
            return convert(root->children.back());
        }
        else
        {
            return createHNode(H_ENDLINE, {});
        }

    case M_DOC:
        DEBUG_LOG(printf("Line: %d\n", __LINE__);)
        if (root->children.size() == 1)
        {
            if(root->children.back()->children.size() == 1)
            {
                return createHNode(H_DOC, {convert(root->children.front())});
            }
            return convert(root->children.back());
        }
        else
        {
            return createHNode(H_DOC, {convert(root->children.front()), convert(root->children.back())});
        }

    default:
        DEBUG_LOG(printf("Line: %d\n", __LINE__);)
        return convert(root->children.back());
    }
        DEBUG_LOG(printf("Line: %d\n", __LINE__);)
    return createHNode(H_NONE, {}, std::string("THIS_IS_NONE"));
}

/**
 * @brief Travers the tree and print Parents and childrens tags in "HTree ParentTag: {Child1Tag, Child2Tag, ...}" format
 *
 * @param root HNode to start traversing
 */
void printTree(struct HNode *root)
{
    H_Tag t = root->tag;
    printf("HTree: %s{", enumHName[t].c_str());
    for (auto hnode : root->children)
    {
        printf("%s, ", enumHName[hnode->tag].c_str());
    }
    printf("}\n");
    for (auto hnode : root->children)
    {
        printTree(hnode);
    }
}

/**
 * @brief Write HTML data from AST to a file
 *
 * @param root Root of AST
 * @param fp File pointer to be written into
 */
void printHTML(struct HNode *root, FILE *fp)
{
    H_Tag t = root->tag;
    DEBUG_LOG(printf("Tag: %s\n", enumHName[t].c_str());)
    switch (t)
    {
    case H_HEAD:
        fprintf(fp, "<h%s>", root->text.c_str());
        DEBUG_LOG(printf("<h%s>", root->text.c_str());)
        printHTML(root->children.back(), fp);
        fprintf(fp, "</h%s>", root->text.c_str());
        DEBUG_LOG(printf("</h%s>", root->text.c_str());)
        break;

    case H_ORD_LIST:
        fprintf(fp, "<ol>\n");
        DEBUG_LOG(printf("<ol>\n");)
        printHTML(root->children.front(), fp);
        fprintf(fp, "</ol>");
        DEBUG_LOG(printf("</ol>");)
        break;

    case H_ORD_LIST_ITEM:
        if (root->children.size() > 1)
        {
            printHTML(root->children.front(), fp);
        }
        fprintf(fp, "<li>");
        DEBUG_LOG(printf("<li>");)
        printHTML(root->children.back(), fp);
        fprintf(fp, "</li>");
        DEBUG_LOG(printf("</li>");)
        break;

    case H_UNORDER_LIST:
        if (root->children.size() == 1)
        {
            fprintf(fp, "<ul>\n");
            DEBUG_LOG(printf("<ul>\n");)
            printHTML(root->children.back(), fp);
        }
        else
        {
            printHTML(root->children.front(), fp);
            if (root->children.front()->tag == root->children.back()->tag)
            {
                fprintf(fp, "</ul>");
                DEBUG_LOG(printf("</ul>");)
            }
            printHTML(root->children.back(), fp);
        }
        if (root->parent->tag != H_UNORDER_LIST)
        {
            fprintf(fp, "</ul>");
            DEBUG_LOG(printf("</ul>");)
        }
        break;

    case H_UNORDER_LIST_ITEM:
        fprintf(fp, "<li>");
        DEBUG_LOG(printf("<li>");)
        printHTML(root->children.front(), fp);
        fprintf(fp, "</li>");
        DEBUG_LOG(printf("</li>");)
        break;

    case H_IMG:
        fprintf(fp, "<img ");
        DEBUG_LOG(printf("<img ");)
        printHTML(root->children.front(), fp);
        fprintf(fp, " ");
        DEBUG_LOG(printf(" ");)
        printHTML(root->children.back(), fp);
        fprintf(fp, ">");
        DEBUG_LOG(printf(">");)
        break;

    case H_ALTTEXT:
        fprintf(fp, " alt=\"");
        DEBUG_LOG(printf(" alt=\"");)
        printHTML(root->children.front(), fp);
        fprintf(fp, "\"");
        DEBUG_LOG(printf("\"");)
        break;

    case H_IMGPATH:
        fprintf(fp, " src=\"");
        DEBUG_LOG(printf(" src=\"");)
        printHTML(root->children.front(), fp);
        fprintf(fp, "\" ");
        DEBUG_LOG(printf("\" ");)
        if (root->children.size() > 1)
        {
            fprintf(fp, " title=");
            DEBUG_LOG(printf(" title=");)
            printHTML(root->children.back(), fp);
        };
        break;

    case H_HYPERLINK:
        fprintf(fp, "<a href=\"");
        DEBUG_LOG(printf("<a href=\"");)
        fprintf(fp, "%s", root->children[1]->text.c_str());
        DEBUG_LOG(printf("%s", root->children[1]->text.c_str());)
        fprintf(fp, "\"");
        DEBUG_LOG(printf("\"");)
        if (root->children.size() > 2)
        {
            fprintf(fp, " title=");
            DEBUG_LOG(printf(" title=");)
            printHTML(root->children.back(), fp);
        }
        fprintf(fp, " >");
        DEBUG_LOG(printf(" >");)
        printHTML(root->children.front(), fp);
        fprintf(fp, "</a>");
        DEBUG_LOG(printf("</a>");)
        break;

    case H_TABLE:
        fprintf(fp, "<table>\n<thead>\n");
        DEBUG_LOG(printf("<table>\n<thead>\n");)
        root->children.front()->tag = H_TABLE_HEAD_S;
        printHTML(root->children.front(), fp);
        fprintf(fp, "</thead>");
        DEBUG_LOG(printf("</thead>");)
        if (root->children.size() > 1)
        {
            fprintf(fp, "<tbody>\n");
            DEBUG_LOG(printf("<tbody>\n");)
            printHTML(root->children.back(), fp);
            fprintf(fp, "</tbody>");
            DEBUG_LOG(printf("</tbody>");)
        }
        fprintf(fp, "</table>");
        DEBUG_LOG(printf("</table>");)
        break;

    case H_TABLE_HEAD_S:
        fprintf(fp, "<tr>");
        DEBUG_LOG(printf("<tr>");)
        if (root->children.size() > 1)
        {
            root->children.front()->tag = H_TABLE_HEAD;
            printHTML(root->children.front(), fp);
            fprintf(fp, "<th>");
            DEBUG_LOG(printf("<th>");)
        }
        printHTML(root->children.back(), fp);
        fprintf(fp, "</th>\n</tr>\n");
        DEBUG_LOG(printf("</th>\n</tr>\n");)
        break;

    case H_TABLE_HEAD:
        if (root->children.size() > 1)
        {
            root->children.front()->tag = H_TABLE_HEAD;
            printHTML(root->children.front(), fp);
        }
        fprintf(fp, "<th>");
        DEBUG_LOG(printf("<th>");)
        printHTML(root->children.back(), fp);
        fprintf(fp, "</th>\n");
        DEBUG_LOG(printf("</th>\n");)
        break;

    case H_TABLE_ELEM:
        fprintf(fp, "<tr>");
        DEBUG_LOG(printf("<tr>");)
        if (root->children.size() > 1)
        {
            printHTML(root->children.front(), fp);
        }
        printHTML(root->children.back(), fp);
        fprintf(fp, "</tr>\n");
        DEBUG_LOG(printf("</tr>\n");)
        break;

    case H_TABLE_SINGLE:
        if (root->children.size() > 1)
        {
            printHTML(root->children.front(), fp);
        }
        fprintf(fp, "<td>");
        DEBUG_LOG(printf("<td>");)
        printHTML(root->children.back(), fp);
        fprintf(fp, "</tb>\n");
        DEBUG_LOG(printf("</tb>\n");)
        break;

    case H_PARA:
        fprintf(fp, "<p>");
        DEBUG_LOG(printf("<p>");)
        printHTML(root->children.front(), fp);
        fprintf(fp, "</p>");
        DEBUG_LOG(printf("</p>");)
        break;

    case H_TEXT:
        fprintf(fp, "%s", root->text.c_str());
        DEBUG_LOG(printf("%s", root->text.c_str());)
        break;

    case H_TEXT_A:
        printHTML(root->children.front(), fp);
        printHTML(root->children.back(), fp);
        break;

    case H_ENDLINE:
        break;

    case H_DOC:
        printHTML(root->children.front(), fp);
        fprintf(fp, "\n");
        DEBUG_LOG(printf("\n");)
        if(root->children.size() > 1)
        {
            printHTML(root->children.back(), fp);
        }
        break;
    }
}

/**
 * @brief Funtion to start AST to HTML file conversion
 *
 * @param root Root object of AST
 * @param fp File pointer to be written into
 */
void printHTMLFile(struct HNode *root, FILE *fp)
{
    fprintf(fp, "<!DOCTYPE html>\n<html>\n<body>\n");
    DEBUG_LOG(printf(" <!DOCTYPE html>\n<html>\n<body>\n");)
    printHTML(root, fp);
    fprintf(fp, "\n</body>\n</html>");
    DEBUG_LOG(printf("\n</body>\n</html>");)
}

#endif //__NODE__