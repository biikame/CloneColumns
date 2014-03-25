#include "Common.h"
#include "Columns.h"
#define PATTERN 2
#if(PATTERN == 1)

Columns* newObject();

void deleteObject(Columns*);

int main()
{
	Columns* columns = newObject();

	deleteObject(columns);
	return 0;
}

Columns* newObject()
{
	Columns* columns = new Columns;
	return columns;
}
void deleteObject(Columns* columns)
{
	delete columns;
}
#else if(PATTERN == 2)

Columns* columns;
void newObject();
void deleteObject();

int main()
{
	srand((unsigned int)time(NULL));//rand()ŠÖ”‚Ìã©‰ñ”ð

	newObject();
	columns->init();
	columns->draw();
	deleteObject();

	return 0;
}

void newObject()
{
	columns = new Columns;
}
void deleteObject()
{
	delete columns;
}
#endif