#include "wallpaperwidget.h"
#include <QIcon>
#include <QHBoxLayout>
#include <QLabel>
#include <QSignalMapper>
#include <QEvent>

using namespace dtb;
using namespace dtb::wallpaper;

WallpaperWidget::WallpaperWidget(QWidget *parent) : QLabel(parent)
{
      initUI();
      initMenu();
}

QMenu *WallpaperWidget::menu() const
{
    return m_menu;
}

void WallpaperWidget::handleAction(const int &action)
{
    switch (action) {
    case Next:
        break;
    case Abount:
        m_about->moveToCenter();
        m_about->show();
        break;
    case Preferences:
        break;
    case Brow:
        break;
    default:
        break;
    }
}

void WallpaperWidget::initUI()
{
    setFixedSize(26, 26);

    QLabel *label = new QLabel;
    label->setFixedSize(22, 22);
    label->setPixmap(QIcon::fromTheme("view-list-details").pixmap(22, 22));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->setContentsMargins(3, 0, 3, 0);

    layout->addWidget(label, 0, Qt::AlignCenter);

    setLayout(layout);

    m_menu = new QMenu(this);

    m_about = new DAboutDialog;

    m_about->setTitle(tr("DreamScene"));
    m_about->setVersion("0.1.1");
    m_about->setWebsiteLink("https://blog.mkacg.com/");
}

void WallpaperWidget::initMenu()
{
    QAction* next = new QAction(tr("Skip to next item"), this);
    QAction* brow = new QAction(tr("Browsing mode"), this);
    QAction* about = new QAction(tr("About DreamSense"), this);
    QAction* preference = new QAction(tr("Preferences..."), this);

    m_menu->addAction(next);
    m_menu->addAction(brow);
    m_menu->addSeparator();
    m_menu->addAction(about);
    m_menu->addAction(preference);

    QSignalMapper *signalMapper = new QSignalMapper(this);

    connect(next, &QAction::triggered, signalMapper, static_cast<void (QSignalMapper::*)()>(&QSignalMapper::map));
    connect(brow, &QAction::triggered, signalMapper, static_cast<void (QSignalMapper::*)()>(&QSignalMapper::map));
    connect(about, &QAction::triggered, signalMapper, static_cast<void (QSignalMapper::*)()>(&QSignalMapper::map));
    connect(preference, &QAction::triggered, signalMapper, static_cast<void (QSignalMapper::*)()>(&QSignalMapper::map));

    signalMapper->setMapping(next, Next);
    signalMapper->setMapping(brow, Brow);
    signalMapper->setMapping(about, Abount);
    signalMapper->setMapping(preference, Preferences);
    connect(signalMapper, static_cast<void (QSignalMapper::*)(const int)>(&QSignalMapper::mapped), this, &WallpaperWidget::handleAction);

}

void WallpaperWidget::setModel(WallpaperModel *model)
{
    m_model = model;
}