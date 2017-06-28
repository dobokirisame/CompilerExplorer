#include "ExplorerOutputPane.h"

ExplorerOutputPane::ExplorerOutputPane(QObject *parent)
    : Core::IOutputPane(parent)
{

}


QWidget *ExplorerOutputPane::outputWidget(QWidget *parent)
{
}

QList<QWidget *> ExplorerOutputPane::toolBarWidgets() const
{
}

QString ExplorerOutputPane::displayName() const
{
}

int ExplorerOutputPane::priorityInStatusBar() const
{
}

void ExplorerOutputPane::clearContents()
{
}

void ExplorerOutputPane::visibilityChanged(bool visible)
{
}

void ExplorerOutputPane::setFocus()
{
}

bool ExplorerOutputPane::hasFocus() const
{
}

bool ExplorerOutputPane::canFocus() const
{
}

bool ExplorerOutputPane::canNavigate() const
{
}

bool ExplorerOutputPane::canNext() const
{
}

bool ExplorerOutputPane::canPrevious() const
{
}

void ExplorerOutputPane::goToNext()
{
}

void ExplorerOutputPane::goToPrev()
{
}
