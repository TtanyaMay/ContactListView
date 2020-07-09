#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "contactsmodel.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    ContactsModel::registerMe("Contacts");
    ContactsModel contactsmodel;
    engine.addImportPath(":/qml");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    //    ContactsModel*  model ;
    //    model->add(Contact("The Shawshank Redemption", "Drama", "111"));
    //    model->add(Contact("The Godfather", "Crime", "222"));
    //    model->add(Contact("Pulp Fiction", "Thriller", "555"));


    return app.exec();
}
