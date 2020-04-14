#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
namespace Ui {
    class GameWindow;
}
class GameWindow : public QMainWindow{
    Q_OBJECT
private slots:
    void onGenerate();
private:
    Ui::GameWindow *ui;
    QGraphicsScene* scene;
    QTimer * animationTimer;
    QTimer* generatorTimer;

public:
    explicit GameWindow(QWidget* parent = 0);
};

#endif // GAMEWINDOW_H
