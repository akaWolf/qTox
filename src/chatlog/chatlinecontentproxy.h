/*
    Copyright © 2014-2015 by The qTox Project

    This file is part of qTox, a Qt-based graphical interface for Tox.

    qTox is libre software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    qTox is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with qTox.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CHATLINECONTENTPROXY_H
#define CHATLINECONTENTPROXY_H

#include <QGraphicsProxyWidget>
#include "chatlinecontent.h"

class FileTransferWidget;

class ChatLineContentProxy : public ChatLineContent
{
public:
    // Type tag to avoid dynamic_cast of contained QWidget*
    enum ChatLineContentProxyType
    {
        GenericType,
        FileTransferWidgetType=0,
    };

public:
    ChatLineContentProxy(QWidget* widget, int minWidth, float widthInPercent = 1.0f);
    ChatLineContentProxy(FileTransferWidget* widget, int minWidth, float widthInPercent = 1.0f);

    virtual QRectF boundingRect() const;
    virtual void setWidth(qreal width);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual qreal getAscent() const;

    QWidget* getWidget() const;
    ChatLineContentProxyType getWidgetType() const;

protected:
    ChatLineContentProxy(QWidget* widget, ChatLineContentProxyType type, int minWidth, float widthInPercent);

private:
    QGraphicsProxyWidget* proxy;
    float widthPercent;
    int widthMin;
    const ChatLineContentProxyType widgetType;
};

#endif // CHATLINECONTENTPROXY_H
