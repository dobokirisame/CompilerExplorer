#ifndef EXPLOREROUTPUTTABLE_H
#define EXPLOREROUTPUTTABLE_H
#include <QTableView>
#include "compilerexplorer_global.h"

namespace compilerExplorer {
namespace gui{
class COMPILEREXPLORERSHARED_EXPORT ExplorerOutputTable : public QTableView
{
	Q_OBJECT
public:
	ExplorerOutputTable(QWidget *parent = 0);
};
}
}
#endif // EXPLOREROUTPUTTABLE_H
