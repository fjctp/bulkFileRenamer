#ifndef FILEOPERATOR_H
#define FILEOPERATOR_H

#include <QObject>
#include <QtCore>

class fileOperator : public QObject
{
    Q_OBJECT
public:
    explicit fileOperator(QObject *parent = 0);

signals:
    void statusChanged(QString);

public slots:
    void set_dir(QString newDir);
    QStringList get_files_info();
    void rename_files();
    bool make_backup();
    int get_new_filenames(QString newFileNames);

    void set_status(QString newStatus);

private:
    QDir dir;
    QFileInfoList fileInfoList;
    QStringList oldNameList;
    QStringList newNameList;
    unsigned int numberOfFiles;

    QString status;

};

#endif // FILEOPERATOR_H
