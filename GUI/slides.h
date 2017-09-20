#ifndef LAYERS_H
#define LAYERS_H

#include <QtGui>
#include <string>
#include "../Utils/misc.h"


namespace Utils {
class GlManager;
}; // namespace Utils


namespace GUI {
class Layer;


class Slides {
  // Q_OBJECT

 public:
  Slides();

  size_t width() const;
  size_t height() const;

  void draw(Utils::GlManager *gl,
            uint top, uint left,
            uint bottom, uint right,
            double zoom);

  bool hasImage() const;

  void backward();
  void forward();

  Layer* current();
  const Layer* current() const;
  Layer* operator[](int i);
  const Layer* operator[](int i) const;

  void add(Layer* l);

  std::string path() const;
 protected:

 private slots:

 private:

  std::vector<Layer*> _slides;
  int _id;

};
}; // namespace GUI

#endif // LAYERS_H