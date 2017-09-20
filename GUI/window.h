#ifndef WINDOW_H
#define WINDOW_H

#include <vector>
#include <string>
#include <QtGui>
#include <QMdiArea>
#include <QApplication>
#include <QMainWindow>

#include "canvas.h"


namespace GUI {

class AboutWindow;
class ImageWindow;
class Slides;


class Window  : public QMainWindow {
  Q_OBJECT

 public:
  Window(QApplication* app);
  QSize sizeHint() const;

  QString _openPath;

 signals:
  void sigUpdateConnectedViews( Canvas*);
  void sigDistributeCoords(QPoint);
  void sigDistributeMarkers(Marker);

 private slots:
  void slotNewWindowAction();
  void slotDialogWindowAction();

 public slots:
  void slotActualizeSubwindowView( ImageWindow*, bool);
  void slotUpdateConnectedViews( Canvas* buf );
  void slotUpdateCoords(QPoint);
  void slotUpdateMarkers(Marker);

 private:
  Slides* _slides;

  QMdiArea* workspace;

  // menu
  QMenu* _windowMenu;
  QAction* _newWindowAct;
  QAction* _dialogWindowAct;

  std::vector<GUI::ImageWindow*> _windows;

  QApplication* _app;

};
}; // namespace GUI

#endif // WINDOW_H
