#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#endif // IMAGELOADER_H
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QPixmap>


namespace Utils
{
    class ImageLoader : public QWidget {
        Q_OBJECT

    public:
        ImageLoader(QWidget *parent = nullptr) : QWidget(parent) {
            QVBoxLayout *layout = new QVBoxLayout(this);
            QPushButton *loadButton = new QPushButton("Load Image", this);
            imageLabel = new QLabel(this);
            imageLabel->setAlignment(Qt::AlignCenter);

            layout->addWidget(loadButton);
            layout->addWidget(imageLabel);

            connect(loadButton, &QPushButton::clicked, this, &ImageLoader::loadImage);
        }

    private slots:
        void loadImage() {
            QString fileName = QFileDialog::getOpenFileName(this, "Open Image", "", "Images (*.png *.jpg *.jpeg *.bmp *.gif)");
            if (!fileName.isEmpty()) {
                QPixmap pixmap(fileName);
                if (!pixmap.isNull()) {
                    imageLabel->setPixmap(pixmap.scaled(imageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
                }
            }
        }

    private:
        QLabel *imageLabel;
    };

}
