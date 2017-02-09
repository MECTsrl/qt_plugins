/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief ATCM slider base class
 */
#include <QPainter>
#include <QVBoxLayout>
#include <QStyleOption>
#include <stdio.h>

#include "atcmslider.h"
#include "common.h"
#include "atcmstyle.h"
#ifdef TARGET_ARM
#include "app_logprint.h"
#include "cross_table_utility.h"
#endif

ATCMslider::ATCMslider(QWidget *parent) :
	QSlider(parent)
{
	m_value = 0;
	m_variable = "";
	m_status = UNK;
    m_CtIndex = 0;
    m_CtVisibilityIndex = 0;
	m_handlerColor = QColor(128,128,128);
	m_addColor = QColor(255,127,80);
	m_subColor = QColor(255,127,80);
	m_icon = QIcon();
    m_visibilityvar = "";
	m_viewstatus = false;

    m_bordercolor = BORDER_COLOR_DEF;
    m_borderwidth = BORDER_WIDTH_DEF;
    m_borderradius = BORDER_RADIUS_DEF;

    //setMinimumSize(QSize(150,50));
	setFocusPolicy(Qt::NoFocus);
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	setStyle(new ATCMStyle);
#ifdef TARGET_ARM
    setToolTip("");
#endif

	/*
	 * put there a default stylesheet
	 */
	setStyleSheet(
#ifndef ENABLE_STYLESHEET
			""
#else
			"/*\n"
			"QSlider::groove:vertical  {\n"
			"    background: transparent;\n"
			"/* absolutely position 4px from the left and right of the widget. setting margins on the widget should work too... */\n"
			"    position: absolute;\n"
			"    left: 4px; right: 4px;\n"
			"}\n"
			"QSlider::handle:vertical  {\n"
			"    height: 31px;\n"
			"    background: transparent;\n"
			"    margin: 0 -4px; /* expand outside the groove */\n"
			"    border-image: url(:/marker.png);\n"
			"}\n"
			"QSlider::add-page:vertical  {\n"
			"    background: transparent;\n"
			"}\n"
			"QSlider::sub-page:vertical  {\n"
			"    background: transparent;\n"
			"}\n"
			"*/\n"
#endif
			);
    m_parent = parent;
#ifdef TARGET_ARM
    connect(m_parent, SIGNAL( varRefresh() ), this, SLOT( updateData() ));
    connect(this, SIGNAL( valueChanged(int) ), this, SLOT( writeValue(int) ));
#endif
}

ATCMslider::~ATCMslider()
{
}

void ATCMslider::paintEvent(QPaintEvent * e)
{
    Q_UNUSED( e );
    QPainter painter(this);
	QPalette palette = this->palette();

	QStyleOptionSlider opt;
	opt.init(this);

	/* sub color */
	palette.setColor(QPalette::ButtonText, m_subColor);
	/* add color */
	palette.setColor(QPalette::Background, m_addColor);
	/* handler color */
	palette.setColor(QPalette::Button, m_handlerColor);
	/* border color */
	palette.setColor(QPalette::Foreground, m_bordercolor);

#ifdef TARGET_ARM
	if (m_viewstatus)
	{
		/* draw the background color in funtion of the status */
		palette.setColor(QPalette::Foreground, Qt::red);
		switch(m_status)
		{
			case DONE:
				palette.setColor(QPalette::Foreground, Qt::green);
				break;
			case BUSY:
				palette.setColor(QPalette::Foreground, Qt::yellow);
				break;
			case ERROR:
				palette.setColor(QPalette::Foreground, Qt::red);
				break;
			default /*UNKNOWN*/:
				palette.setColor(QPalette::Foreground, Qt::gray);
				break;
		}
	}
#endif

	opt.palette = palette;
	_diameter_ = m_borderradius;
	_penWidth_ = m_borderwidth;

	if (m_apparence == QFrame::Raised)
	{
        opt.state = QStyle::State_Raised;
	}
	else if (m_apparence == QFrame::Sunken)
	{
        opt.state = QStyle::State_Sunken;
	}

	opt.orientation = QSlider::orientation();
	opt.maximum = QSlider::maximum();
	opt.minimum = QSlider::minimum();
	opt.sliderValue = QSlider::value();
	opt.rect = QSlider::rect();
	opt.pageStep = QSlider::pageStep();
	opt.upsideDown = QSlider::invertedAppearance();
	_icon_ = m_icon;

	style()->drawComplexControl(QStyle::CC_Slider, &opt, &painter, this);
}

void ATCMslider::setViewStatus(bool status)
{
	m_viewstatus = status;
	update();
}

bool ATCMslider::setVisibilityVar(QString visibilityVar)
{
    if (visibilityVar.trimmed().length() == 0)
    {
        m_visibilityvar.clear();
        m_CtVisibilityIndex = 0;
        return true;
    }
    else
    {
#ifdef TARGET_ARM
        int CtIndex;
        if (Tag2CtIndex(visibilityVar.trimmed().toAscii().data(), &CtIndex) == 0)
        {
            LOG_PRINT(verbose_e,"visibilityVar '%s', CtIndex %d\n", m_visibilityvar.toAscii().data(), m_CtVisibilityIndex);
            m_CtVisibilityIndex = CtIndex;
#endif
            m_visibilityvar = visibilityVar.trimmed();
            return true;
#ifdef TARGET_ARM
        }
        else
        {
            m_CtVisibilityIndex = 0;
            LOG_PRINT(error_e,"visibilityVar '%s', CtIndex %d\n", visibilityVar.trimmed().toAscii().data(), CtIndex);
            return false;
        }
#endif
    }
}

/* Write variable */
bool ATCMslider::writeValue(int value)
{
	if (m_variable.length() == 0)
	{
		return false;
	}

	m_value = value;
	//this->setValue(m_value);
#ifdef TARGET_ARM
    if (m_CtIndex > 0 && setFormattedVarByCtIndex(m_CtIndex, QString::number(m_value).toAscii().data()) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
#else
	return true;
#endif
}

/* Activate variable */
bool ATCMslider::setVariable(QString variable)
{
    m_variable = variable.trimmed();
#ifdef TARGET_ARM
    if (Tag2CtIndex(m_variable.toAscii().data(), &m_CtIndex) != 0)
    {
        LOG_PRINT(error_e, "cannot extract ctIndex\n");
        m_status = ERROR;
        //m_value = VAR_UNKNOWN;
        m_CtIndex = 0;
    }
    else
    {
        m_status = DONE;
    }
    LOG_PRINT(verbose_e, "'%s' -> ctIndex %d\n", m_variable.toAscii().data(), m_CtIndex);
#endif

#ifndef TARGET_ARM
    setToolTip(m_variable);
#else
    setToolTip("");
#endif
    return true;
}

QColor ATCMslider::borderColor() const
{
	return m_bordercolor;
}

void ATCMslider::setBorderColor(const QColor& color)
{
	m_bordercolor = color;
	update();
}

QColor ATCMslider::handlerColor() const
{
	return m_handlerColor;
}

void ATCMslider::setHandlerColor(const QColor& color)
{
	m_handlerColor = color;
	update();
}

QColor ATCMslider::subColor() const
{
	return m_subColor;
}

void ATCMslider::setSubColor(const QColor& color)
{
	m_subColor = color;
	update();
}

QColor ATCMslider::addColor() const
{
	return m_addColor;
}

void ATCMslider::setAddColor(const QColor& color)
{
	m_addColor = color;
	update();
}

void ATCMslider::setBorderWidth(int width)
{
	m_borderwidth = width;
	update();
}

void ATCMslider::setBorderRadius(int radius)
{
	m_borderradius = radius;
	update();
}

bool ATCMslider::setRefresh(int refresh)
{
	m_refresh = refresh;
	return true;
}

/* read variable */
void ATCMslider::updateData()
{
#ifdef TARGET_ARM
    if (m_CtVisibilityIndex > 0) {
        uint32_t visible = 0;
        if (readFromDbLock(m_CtVisibilityIndex, &visible) == 0) {
            m_status = DONE;
            if (visible && ! this->isVisible()) {
                this->setVisible(true);
            }
            else if (! visible && this->isVisible()) {
                this->setVisible(false);
            }
        }
    }
    if (! this->isVisible()) {
        return;
    }

    if (m_CtIndex > 0)
	{
        int ivalue;
        if (formattedReadFromDb_int(m_CtIndex, &ivalue) == 0)
		{
            m_value = ivalue;
            m_status = DONE;
        }
		else
		{
			//m_value = VAR_UNKNOWN;
			m_status = ERROR;
		}
	}
	else
	{
		m_status = ERROR;
	}
#endif
	if (m_status == DONE)
	{
        disconnect( this, SIGNAL( valueChanged(int) ), this, SLOT( writeValue(int) ) );
        this->setValue(m_value);
        connect( this, SIGNAL( valueChanged(int) ), this, SLOT( writeValue(int) ) );
    }
	this->update();
}

QIcon ATCMslider::icon() const
{
	return m_icon;
}

void ATCMslider::setIcon(const QIcon& icon)
{
	m_icon = icon;
	update();
}

enum QFrame::Shadow ATCMslider::apparence() const
{
    return m_apparence;
}

void ATCMslider::setApparence(const enum QFrame::Shadow apparence)
{
    m_apparence = apparence;
    update();
}

void ATCMslider::unsetVariable()
{
    setVariable("");
}

void ATCMslider::unsetRefresh()
{
    setRefresh(DEFAULT_PLUGIN_REFRESH);
}

void ATCMslider::unsetViewStatus()
{
    setViewStatus(false);
}

void ATCMslider::unsetVisibilityVar()
{
    setVisibilityVar("");
}

void ATCMslider::unsetApparence()
{
    setApparence(QFrame::Plain);
}
