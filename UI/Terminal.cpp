/*!
 * \file Terminal.cpp
 *
 * \brief Terminal module interface
 *
 * \author      De Buscchere Yanis - EPFL EL BA3
 * \date        24.03.2021
 */

#include "Terminal.h"

#include <qstyle.h>
#include <qtextcursor.h>

#include <QScrollBar>
#include <QTextBlock>
#include <QtCore/QDebug>
#include <iostream>

Terminal::Terminal(QWidget *parent) : QPlainTextEdit(parent), localEchoEnabled(false) {
  document()->setMaximumBlockCount(100);
  setStyleSheet(
      QLatin1String("background-color: rgb(30, 30, 30);\n"
                    "border: 0;\n"
                    "color: rgb(255, 255, 255);"));
  QPalette p = palette();
  p.setColor(QPalette::Base, Qt::black);
  p.setColor(QPalette::Text, Qt::red);
  setPalette(p);
  insertPlainText(QString::fromStdString(prompt).toLocal8Bit());
  unremovable = prompt.length();
}

void Terminal::keyPressEvent(QKeyEvent *e) {
  switch (e->key()) {
    case Qt::Key_Right:
      QPlainTextEdit::keyPressEvent(e);
      break;
    case Qt::Key_Down:
    case Qt::Key_Up:
      break;
    case Qt::Key_Left:
      if (textCursor().position() > unremovable) {
        QPlainTextEdit::keyPressEvent(e);
      }
      break;
    case Qt::Key_Backspace:
      if (textCursor().position() > unremovable) {
        QPlainTextEdit::keyPressEvent(e);
        currentCommand.pop_back();
      }
      break;
    case Qt::Key_Return:
      QPlainTextEdit::keyPressEvent(e);
      handleCommand();
      break;
    default:
      QPlainTextEdit::keyPressEvent(e);
      currentCommand.append(e->text().toStdString());
      break;
  }
}

void Terminal::handleCommand() {
  currentCommand = stripCommand(currentCommand);
  commandHistory.push_back(currentCommand);
  std::cout << currentCommand << std::endl;
  if (currentCommand == "clear") {
    clear();
    insertPlainText(QString::fromStdString(prompt).toLocal8Bit());
  } else {
    textCursor().deletePreviousChar();
    appendHtml(QString::fromStdString("<font color=\"red\">Command not found: " + currentCommand + "</font><br>").toLocal8Bit());
    insertPlainText(QString::fromStdString(prompt).toLocal8Bit());
  }

  currentCommand.clear();
  unremovable = textCursor().position();
}

void Terminal::mousePressEvent(QMouseEvent *e) {
  Q_UNUSED(e)
  setFocus();
}

void Terminal::mouseDoubleClickEvent(QMouseEvent *e) { Q_UNUSED(e) }

void Terminal::contextMenuEvent(QContextMenuEvent *e) { Q_UNUSED(e) }

std::string Terminal::stripCommand(const std::string command) const {
  const char *WhiteSpace = " \t\v\r\n";
  std::size_t start = command.find_first_not_of(WhiteSpace);
  std::size_t end = command.find_last_not_of(WhiteSpace);
  return start == end ? std::string() : command.substr(start, end - start + 1);
}
