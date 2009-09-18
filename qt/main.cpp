#include <QTextStream>
#include <QStringList>

#include "todo3r.h"

int main(int argc, char* argv[]) {
	QTextStream out(stdout), err(stderr);
	QStringList listOfFiles;

	int i;
	for( i=1; i<argc; i++ )
		listOfFiles << argv[i];

	if( listOfFiles.size()==0 )
		listOfFiles << ".";

	// in future, we can supply list of files to ignore.
	// then we will just remove the file names from this list.

	Todo3r theApp(listOfFiles, out, err);
	theApp.start();

	return 0;
}
