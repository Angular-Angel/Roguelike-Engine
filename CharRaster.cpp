#include "CharRaster.h"
#include <iostream>

CharRaster::CharRaster(unsigned int x, unsigned int y, char ch, charAttr chAt)
{
    charImage = vector<vector<char> >();
    charAttrs = vector<vector<charAttr> >();
    for (unsigned int i = 0; i < y; i++)
    {
        charImage.push_back(vector<char>());
        charAttrs.push_back(vector<charAttr>());
        for (unsigned int j = 0; j < x; j++)
        {
            charImage[i].push_back(ch);
            charAttrs[i].push_back(chAt);
        }
    }
}

void CharRaster::insertCharRaster(CharRaster ch, int x, int y)
{
    /*
    bool gx(false), gy(false);
    if (ch.getWidth() + x > getWidth())
    gx = true;
    if(ch.getHeight() + y > getHeight())
    gy = true;
    if (gy && gx)
    resize(ch.getWidth() + x, ch.getHeight() + y);
    else if (gx && !gy)
    resize(ch.getWidth() + x, getHeight());
    else if (!gx && gy)
    resize(getWidth(), ch.getHeight() + y);
    */
    for (unsigned int i = 0; i < ch.getHeight(); i++)
    {
        for (unsigned int j = 0; j < ch.getWidth(); j++)
        {
            if (x + j < getWidth() && x + j > 0 && y + i < getHeight() && y + i > 0 && ch.getChar(j, i) != ' ')
            {
                setCharAttr(x + j, y + i, ch.getCharAttr(j, i), ch.getChar(j, i));
            }
        }

    }
}

void CharRaster::resize(unsigned int x, unsigned int y)
{
    if (y > getHeight())
    for (unsigned int i = getHeight(); i < y; i++)
    {
        charImage.push_back(vector<char>());
        charAttrs.push_back(vector<charAttr>());
        for(unsigned int j = 0; j < getWidth(); j++)
        {
            charImage[i].push_back(' ');
            charAttrs[i].push_back(WHITEBLACK);
        }

    }
    else if (y < getHeight())
    for (unsigned int i = y; i > getHeight(); i--)
    {
        charImage.pop_back();
        charAttrs.pop_back();
    }

    if (x > getWidth())
    for (unsigned int i = 0; i < getHeight(); i++)
    {
        for (unsigned int j = getWidth(i); j < x; j++)
        {
            charImage[i].push_back(' ');
            charAttrs[i].push_back(WHITEBLACK);
        }
    }
    else if (x < getWidth())
    for (unsigned int i = 0; i < getHeight(); i++)
    {
        for (unsigned int j = x; j > getWidth(); j--)
        {
            charImage[i].pop_back();
            charAttrs[i].pop_back();
        }

    }
}

void CharRaster::rotate(Rotation r)
{
    switch (r)
    {
        case DEGREE_0:
        return;
        case DEGREE_90:
        {
            vector<vector<charAttr> > newAttrImage = vector<vector<charAttr> >();
            vector<vector<char> > newImage = vector<vector<char> >();
            for (unsigned int i = 0; i < getWidth(); i++)
            {
                newImage.push_back(vector<char>());
                newAttrImage.push_back(vector<charAttr>());
                for (unsigned int j = 0; j < getHeight(); j++)
                {
                    newImage[i].push_back(getChar(i, getHeight() -1 - j));
                    newAttrImage[i].push_back(getCharAttr(i, getHeight() -1 - j));
                }

            }
            charImage = newImage;
            charAttrs = newAttrImage;
            break;
        }
        case DEGREE_180:
        {
            vector<vector<charAttr> > newAttrImage = vector<vector<charAttr> >();
            vector<vector<char> > newImage = vector<vector<char> >();
            for (unsigned int i = 0; i < getHeight(); i++)
            {
                newImage.push_back(vector<char>());
                newAttrImage.push_back(vector<charAttr>());
                for (unsigned int j = 0; j < getWidth(); j++)
                {
                    newImage[i].push_back(getChar(getWidth() -1 - j, getHeight() -1 - i));
                    newAttrImage[i].push_back(getCharAttr(getWidth() -1 - j, getHeight() -1 - i));
                }

            }
            charImage = newImage;
            charAttrs = newAttrImage;
            break;
        }
        case DEGREE_270:
        {
            vector<vector<charAttr> > newAttrImage = vector<vector<charAttr> >();
            vector<vector<char> > newImage = vector<vector<char> >();
            for (unsigned int i = 0; i < getWidth(); i++)
            {
                newImage.push_back(vector<char>());
                newAttrImage.push_back(vector<charAttr>());
                for (unsigned int j = 0; j < getHeight(); j++)
                {
                    newImage[i].push_back(getChar(getWidth() -1 - i, j));
                    newAttrImage[i].push_back(getCharAttr(getWidth() - 1 -i, j));
                }

            }
            charImage = newImage;
            charAttrs = newAttrImage;
            break;
        }

    }
}

void CharRaster::flipHorizontal()
{
    vector<vector<char> > newImage = vector<vector<char> >();
    vector<vector<charAttr> > newAttrImage = vector<vector<charAttr> >();
    for (unsigned int i = 0; i < getHeight(); i++)
    {
        newImage.push_back(vector<char>());
        newAttrImage.push_back(vector<charAttr>());
        for (unsigned int j = 0; j < getWidth(); j++)
        {
            newImage[i].push_back(getChar(getWidth() -1 - j, i));
            newAttrImage[i].push_back(getCharAttr(getWidth() -1 - j, i));
        }

    }
    charImage = newImage;
    charAttrs = newAttrImage;
}

void CharRaster::flipVertical()
{
    vector<vector<char> > newImage = vector<vector<char> >();
    vector<vector<charAttr> > newAttrImage = vector<vector<charAttr> >();
    for (unsigned int i = 0; i < getHeight(); i++)
    {
        newImage.push_back(vector<char>());
        newAttrImage.push_back(vector<charAttr>());
        for (unsigned int j = 0; j < getWidth(); j++)
        {
            newImage[i].push_back(getChar(j, getHeight() -1 - i));
            newAttrImage[i].push_back(getCharAttr(j, getHeight() -1 - i));
        }
    }
    charImage = newImage;
    charAttrs = newAttrImage;
}

void CharRaster::print(int x, int y, WINDOW* win)
{
    for (unsigned int i = 0; i < getHeight(); i++)
    {
        for (unsigned int j = 0; j < getWidth(i); j++)
        {
            wattron(win, getCharAttr(j, i));
            mvwaddch(win, y + i, x + j, getChar(j, i));
            wattroff(win, getCharAttr(j, i));
        }
    }
}

CharRaster::~CharRaster()
{
    //dtor
}
