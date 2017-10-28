#ifndef WallpaperPLUGIN_H
#define WallpaperPLUGIN_H

#include "../interfaces/pluginsiteminterface.h"
#include "wallpaperpopupwidget.h"
#include "wallpaperwidget.h"
#include <QObject>

namespace dtb {
namespace wallpaper {

class WallpaperWorker;
class WallpaperModel;

class WallpaperPlugin : public QObject, public PluginsItemInterface
{
    Q_OBJECT
public:
    WallpaperPlugin(QObject *parent = nullptr);

    const QString pluginName() const Q_DECL_OVERRIDE;
    void init(PluginProxyInterface *proxyInter) Q_DECL_OVERRIDE;

    QWidget *itemWidget(const QString &itemKey) Q_DECL_OVERRIDE;

    QMenu* itemContextMenu(const QString &itemKey) Q_DECL_OVERRIDE;

private:
    PluginProxyInterface *m_proxyInter;
    WallpaperPopupWidget *m_popupWidget;
    WallpaperWidget *m_Wallpaper;
    WallpaperModel *m_model;
    WallpaperWorker *m_worker;
};
}
}

#endif // WallpaperPLUGIN_H