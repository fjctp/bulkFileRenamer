#include "fileoperator.h"
#include <QtCore>

fileOperator::fileOperator(QObject *parent) :
    QObject(parent)
{

}

// Get files infomation in the working directory
QStringList fileOperator::get_files_info()
{
    fileInfoList=dir.entryInfoList();
    int i;
    for(i=0;i<fileInfoList.size();i++)
    {
        oldNameList.append(fileInfoList.at(i).fileName());
        qDebug() << i << ',' << oldNameList.at(i);
    }

    return oldNameList;
}

// Create backup and rename files in the working directory
void fileOperator::rename_files()
{
    if(!make_backup())
        exit(1);
    else
    {
        int i;
        for(i=0;i<newNameList.size();i++)
        {
            QString oldFile=dir.absolutePath()+'/'+oldNameList.at(i);
            QString newFile=dir.absolutePath()+'/'+newNameList.at(i);

            qDebug() << i;
            qDebug() << oldFile;
            qDebug() << newFile;
            qDebug() << '\n';
            QFile::rename(oldFile,newFile);
        }
    }
}

// Copy files in the working directory to the folder, backup
bool fileOperator::make_backup()
{
    QString backupFolderName="backup";
    bool sucess=dir.mkdir(backupFolderName);
    qDebug() << sucess;

    if(sucess)
    {
        int i;
        for(i=0;i<oldNameList.size();i++)
        {
            QString orginalPath=dir.absolutePath()+'\\';
            QString backupPath=orginalPath+backupFolderName+'\\';
            QString fileName=oldNameList.at(i);
            QFile::copy(orginalPath+fileName,backupPath+fileName);
        }
        return TRUE;
    }
    return FALSE;
}

// Set the working directory path
void fileOperator::set_dir(QString newDir)
{
    dir=QDir(newDir);
    qDebug() << dir.absolutePath();

    // Show files only
    dir.setFilter(QDir::Files);
}

// Get the new filenames
int fileOperator::get_new_filenames(QString newFileNames)
{
    newNameList=newFileNames.split('\n');
    qDebug() << newNameList;
    return newNameList.size();
}

//
void fileOperator::set_status(QString newStatus)
{

}
