#ifndef RS_DEMO_GDAL_H
#define RS_DEMO_GDAL_H

#include <QMainWindow>

namespace Ui {
class RS_DEMO_GDAL;
}

class RS_DEMO_GDAL : public QMainWindow
{
    Q_OBJECT

public:
    explicit RS_DEMO_GDAL(QWidget *parent = 0);
    ~RS_DEMO_GDAL();

private:
    Ui::RS_DEMO_GDAL *ui;
};

#endif // RS_DEMO_GDAL_H
