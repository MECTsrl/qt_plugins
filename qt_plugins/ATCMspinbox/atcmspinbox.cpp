/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief ATCM spinbox base class
 */
#include <QPainter>
#include <QVBoxLayout>
#include <QStyleOption>

#include "atcmspinbox.h"
#include "common.h"
#include "atcmstyle.h"
#ifdef TARGET_ARM
#include "app_logprint.h"
#include "cross_table_utility.h"
#endif

ATCMspinbox::ATCMspinbox(QWidget *parent) :
    QDoubleSpinBox(parent)
{
    m_value = 0;
    m_variable = "";
    m_status = UNK;
    m_CtIndex = 0;
    m_CtVisibilityIndex = 0;
    m_labelcolor = QColor(230,230,230);
    m_objectstatus = false;
    m_visibilityvar = "";

    m_bgcolor = BG_COLOR_DEF;
    m_fontcolor = FONT_COLOR_DEF;
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
                "QDoubleSpinBox\n"
                "{\n"
                "    font: 18pt \""FONT_TYPE"\";\n"
                "    background-color: rgb(230, 230, 230);\n"
                "    border:2px solid black;\n"
                "    border-radius:4px;\n"
                "    qproperty-alignment: AlignCenter;\n"
                "}\n"
                "QDoubleSpinBox::up-button {\n"
                "    subcontrol-origin: content;\n"
                "    subcontrol-position: right center;\n"
                "    min-height: 25px;\n"
                "    min-width: 25px;\n"
                "    background-color: rgb(230, 230, 230);\n"
                "}\n"
                "QDoubleSpinBox::up-arrow {\n"
                "    border-image: url(:/right.png);\n"
                "}\n"
                "QDoubleSpinBox::down-button {\n"
                "    subcontrol-origin: content;\n"
                "    subcontrol-position: left center;\n"
                "    min-height: 25px;\n"
                "    min-width: 25px;\n"
                "    background-color: rgb(230, 230, 230);\n"
                "}\n"
                "QDoubleSpinBox::down-arrow {\n"
                "    border-image: url(:/left.png);\n"
                "}\n"
                "*/\n"
            #endif
                );
    m_parent = parent;
#ifdef TARGET_ARM
    connect(m_parent, SIGNAL(varRefresh()), this, SLOT(updateData()));
    connect( this, SIGNAL( valueChanged(double) ), this, SLOT( writeValue(double) ) );
#endif
}

ATCMspinbox::~ATCMspinbox()
{
}

void ATCMspinbox::paintEvent(QPaintEvent * e)
{
    Q_UNUSED( e );
    QPainter painter(this);
    QPalette palette = this->palette();

    QStyleOptionSpinBox opt;
    opt.init(this);

    /* font color */
    palette.setColor(QPalette::Text,m_fontcolor);
    /* label color */
    palette.setColor(QPalette::ButtonText,m_labelcolor);
    /* border color */
    palette.setColor(QPalette::Foreground, m_bordercolor);
    /* bg color */
    palette.setColor(QPalette::Button, m_bgcolor);

    if (m_apparence == QFrame::Raised)
    {
        opt.state = QStyle::State_Raised;
    }
    else if (m_apparence == QFrame::Sunken)
    {
        opt.state = QStyle::State_Sunken;
    }


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

    style()->drawComplexControl(QStyle::CC_SpinBox, &opt, &painter, this);
}

void ATCMspinbox::setViewStatus(bool status)
{
    m_viewstatus = status;
    update();
}

bool ATCMspinbox::setVisibilityVar(QString visibilityVar)
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
            LOG_PRINT(verbose_e,"visibilityVar '%s', CtIndex %d\n", m_visibilityvar.trimmed().toAscii().data(), m_CtVisibilityIndex);
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
bool ATCMspinbox::writeValue(double value)
{
    if (m_variable.length() == 0)
    {
        m_value = (float)value;
        disconnect( this, SIGNAL( valueChanged(double) ), this, SLOT( writeValue(double) ) );
        this->setValue(m_value);
        connect( this, SIGNAL( valueChanged(double) ), this, SLOT( writeValue(double) ) );
        return false;
    }
#ifdef TARGET_ARM
    if (m_CtIndex > 0 && setFormattedVarByCtIndex(m_CtIndex, QString::number(value).toAscii().data()) == 0)
    {
        m_value = (float)value;
        disconnect( this, SIGNAL( valueChanged(double) ), this, SLOT( writeValue(double) ) );
        this->setValue(m_value);
        connect( this, SIGNAL( valueChanged(double) ), this, SLOT( writeValue(double) ) );
        return true;
    }
    else
    {
        disconnect( this, SIGNAL( valueChanged(double) ), this, SLOT( writeValue(double) ) );
        this->setValue(m_value);
        connect( this, SIGNAL( valueChanged(double) ), this, SLOT( writeValue(double) ) );
        return false;
    }
#else
    m_value = (float)value;
    this->setValue(m_value);
    return true;
#endif
}

/* Activate variable */
bool ATCMspinbox::setVariable(QString variable)
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
        switch (CtIndex2Type(m_CtIndex))
        {
        case intab_e:
        case intba_e:
        case uintab_e:
        case uintba_e:
        case dint_abcd_e:
        case dint_badc_e:
        case dint_cdab_e:
        case dint_dcba_e:
        case udint_abcd_e:
        case udint_badc_e:
        case udint_cdab_e:
        case udint_dcba_e:
            QDoubleSpinBox::setDecimals(0);
            break;
        case fabcd_e:
        case fbadc_e:
        case fcdab_e:
        case fdcba_e:
        {
            int decimal = 0;
            if (varNameArray[m_CtIndex].decimal > 4)
            {
                if (readFromDbLock(varNameArray[m_CtIndex].decimal, &decimal) != 0)
                {
                    decimal = 0;
                }
            }
            else if (varNameArray[m_CtIndex].decimal > 0)
            {
                LOG_PRINT(verbose_e, "Decimal %d\n", varNameArray[m_CtIndex].decimal);
                decimal = varNameArray[m_CtIndex].decimal;
            }
            else
            {
                decimal = 0;
            }

            QDoubleSpinBox::setDecimals(decimal);
        }
            break;
        default:
            QDoubleSpinBox::setDecimals(0);
        }

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

QColor ATCMspinbox::bgColor() const
{
    return m_bgcolor;
}

void ATCMspinbox::setBgColor(const QColor& color)
{
    m_bgcolor = color;
    update();
}

QColor ATCMspinbox::borderColor() const
{
    return m_bordercolor;
}

void ATCMspinbox::setBorderColor(const QColor& color)
{
    m_bordercolor = color;
    update();
}

QColor ATCMspinbox::fontColor() const
{
    return m_fontcolor;
}

void ATCMspinbox::setFontColor(const QColor& color)
{
    m_fontcolor = color;
    update();
}

QColor ATCMspinbox::labelColor() const
{
    return m_labelcolor;
}

void ATCMspinbox::setLabelColor(const QColor& color)
{
    m_labelcolor = color;
    update();
}

void ATCMspinbox::setBorderWidth(int width)
{
    m_borderwidth = width;
    update();
}

void ATCMspinbox::setBorderRadius(int radius)
{
    m_borderradius = radius;
    update();
}

bool ATCMspinbox::setRefresh(int refresh)
{
    m_refresh = refresh;
    return true;
}

/* read variable */
void ATCMspinbox::updateData()
{
#ifdef TARGET_ARM
    char statusMsg[TAG_LEN] = "";

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
        float fvalue;
        if (formattedReadFromDb_float(m_CtIndex, &fvalue) == 0)
        {
            m_status = DONE;
            m_value = fvalue;
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

    disconnect( this, SIGNAL( valueChanged(double) ), this, SLOT( writeValue(double) ) );
    if (m_status == ERROR)
    {
        /* set error MSG */
        if (strlen(statusMsg) > 0)
        {
            setSpecialValueText(statusMsg);
        }
    }
    else if (m_status == DONE)
    {
        this->setValue(m_value);
    }
    connect( this, SIGNAL( valueChanged(double) ), this, SLOT( writeValue(double) ) );
#endif
    this->update();
}

enum QFrame::Shadow ATCMspinbox::apparence() const
{
    return m_apparence;
}

void ATCMspinbox::setApparence(const enum QFrame::Shadow apparence)
{
    m_apparence = apparence;
    update();
}

void ATCMspinbox::unsetVariable()
{
    setVariable("");
}

void ATCMspinbox::unsetRefresh()
{
    setRefresh(DEFAULT_PLUGIN_REFRESH);
}

void ATCMspinbox::unsetViewStatus()
{
    setViewStatus(false);
}

void ATCMspinbox::unsetVisibilityVar()
{
    setVisibilityVar("");
}

void ATCMspinbox::unsetApparence()
{
    setApparence(QFrame::Plain);
}
