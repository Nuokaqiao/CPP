#include "rs_demo_gdal.h"
#include "ui_rs_demo_gdal.h"

RS_DEMO_GDAL::RS_DEMO_GDAL(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RS_DEMO_GDAL)
{
    ui->setupUi(this);
}

RS_DEMO_GDAL::~RS_DEMO_GDAL()
{
    delete ui;
}
