#include "todo3r.h"

#include "todofinder.h"

Todo3r::Todo3r(QStringList listOfFiles, QTextStream &out, QTextStream &err)
	: listOfFiles(listOfFiles), out(out), err(err)
{}

void Todo3r::start() {
	foreach( QString filename, listOfFiles )
		TodoFinder(filename, out, err).findTodo();
}
