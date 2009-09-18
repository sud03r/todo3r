#ifndef TODOFINDER_H
#define TODOFINDER_H

#include <QString>
#include <QTextStream>

class TodoFinder
{
public:
	TodoFinder(QString filename, QTextStream &out, QTextStream &err);
	void findTodo();
protected:
	QString filename;
	QTextStream &out, &err;
};

#endif // TODOFINDER_H
