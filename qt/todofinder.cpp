#include "todofinder.h"

#include <QFileInfo>
#include <QFile>
#include <QDir>

#include "todo3r.h"

TodoFinder::TodoFinder(QString filename, QTextStream &out, QTextStream &err)
	: filename(filename), out(out), err(err)
{}

void TodoFinder::findTodo() {
/*
Steps:
1. check if the file exists
	> if not, print error, return
2. check if its a file or a directory
	> if its a dir, get file list, call TodoFinder for each file
3. read each line, see if it contains "todo" (case insensitive)
	> if yes, print "file (line number) : line"
*/
	if( !QFile::exists(filename) ) {
		err << QString("file \"%1\" does not exist!").arg(filename) << "\n";
		return;
	}
	QFileInfo fileinfo(filename);
	if( fileinfo.isFile() ) {
		QFile file(filename);
		file.open(QIODevice::ReadOnly);
		int lineNum=1;
		while(file.bytesAvailable()) {
			QString line(file.readLine());
			if( line.contains("todo",Qt::CaseInsensitive) ) {
				out << QString("%1 (%2): %3").arg(filename).arg(lineNum).arg(line);
			}
			lineNum++;
		}
	} else if( fileinfo.isDir() ) {
		QStringList list = QDir(filename).entryList(QDir::Dirs|QDir::Files|QDir::NoDotAndDotDot, QDir::Name);
		QStringList::iterator iter;
		for( iter=list.begin(); iter!=list.end(); iter++ )
			*iter = filename + "/" + *iter;
		Todo3r(list, out, err).start();
	} else {
		err << QString("Unknown error: \"%1\" is neither a file, nor a directory!").arg(filename) << '\n';
	}
}
