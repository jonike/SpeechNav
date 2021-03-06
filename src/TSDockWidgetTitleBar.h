/* Zhan: Take some codes from KoOffice
   
   This file is part of the KDE project
   Copyright (c) 2007 Marijn Kruisselbrink <m.kruisselbrink@student.tue.nl>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/
#ifndef TSDOCKWIDGETTITLEBAR_H_
#define TSDOCKWIDGETTITLEBAR_H_

#include "TSWebApp.h"

#include <QAbstractButton>
#include <QtGui/QDockWidget>
#include <QIcon>

/**
 * @short A custom title bar for dock widgets.
 *
 * Allow customization such as collapsable, or hidding text.
 * 
 * @see TSDockWidgetTitleBarButton
 */

class TSDockWidgetTitleBar;


class TSWEBAPP_EXPORTS TSDockWidgetTitleBarPrivate
{
public:
    TSDockWidgetTitleBarPrivate(TSDockWidgetTitleBar* thePublic);

    friend class TSDockWidgetTitleBar;
    
	TSDockWidgetTitleBar* thePublic;
	QIcon openIcon, closeIcon;
    QAbstractButton* closeButton;
    QAbstractButton* floatButton;
    QAbstractButton* collapseButton;
    
    bool textVisible;
    bool ignoreTextSize;

    void toggleFloating();
    void toggleCollapsed();
    void featuresChanged(QDockWidget::DockWidgetFeatures features);
};

class TSWEBAPP_EXPORTS TSDockWidgetTitleBar : public QWidget
{
    Q_OBJECT
public:
    TSDockWidgetTitleBar(QDockWidget* dockWidget);
    virtual ~TSDockWidgetTitleBar();

    virtual QSize minimumSizeHint() const; ///< reimplemented from QWidget
    virtual QSize sizeHint() const;  ///< reimplemented from QWidget

    void setCollapsed(bool collapsed);
    
    void setCollapsable(bool collapsable);
    void setTextVisible(bool visible);
    /// Define wether the text size should be ignored in @ref sizeHint
    void setIgnoreTextSize(bool ignore);

protected:
    virtual void paintEvent(QPaintEvent* event); ///< reimplemented from QWidget
    virtual void resizeEvent(QResizeEvent* event); ///< reimplemented from QWidget
private:
	Q_PRIVATE_SLOT(d, void toggleFloating())
    Q_PRIVATE_SLOT(d, void toggleCollapsed())
    Q_PRIVATE_SLOT(d, void featuresChanged(QDockWidget::DockWidgetFeatures))

	friend class TSDockWidgetTitleBarPrivate;
    TSDockWidgetTitleBarPrivate * const d;
};

#endif // TSDOCKWIDGETTITLEBAR_H_
