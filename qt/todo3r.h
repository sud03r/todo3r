#ifndef TODO3R_H
#define TODO3R_H

#include <QStringList>
#include <QTextStream>

class Todo3r
{
public:
	Todo3r(QStringList listOfFiles, QTextStream &out, QTextStream &err);
	void start();

protected:
	QStringList listOfFiles;
	QTextStream &out, &err;
};

#endif // TODO3R_H
