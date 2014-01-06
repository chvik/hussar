#include "hussarcommandlineedit.h"

HussarCommandLineEdit::HussarCommandLineEdit(HussarSession *session, QWidget *parent) :
    QLineEdit(parent),
    session(session)
{
    connect(this, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
}

void HussarCommandLineEdit::onEditingFinished()
{
    if (!text().isEmpty()) {
        session->execute(text());
        setText("");
    }
}
