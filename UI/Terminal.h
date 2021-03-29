/*!
 * \file Terminal.h
 *
 * \brief Terminal module interface
 *
 * \author      De Buscchere Yanis - EPFL EL BA3
 * \date        24.03.2021
 */

#ifndef TERMINAL_H
#define TERMINAL_H

#include <QPlainTextEdit>
#include <string>

class Terminal : public QPlainTextEdit {
  Q_OBJECT

 signals:
  void getData(const QByteArray &data);

 public:
  Terminal(QWidget *parent = nullptr);

  ~Terminal(){};

 protected:
  void keyPressEvent(QKeyEvent *e) Q_DECL_OVERRIDE;
  void mousePressEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
  void mouseDoubleClickEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
  void contextMenuEvent(QContextMenuEvent *e) Q_DECL_OVERRIDE;
  void handleCommand();
  std::string stripCommand(const std::string command) const;

 private:
  const std::string prompt = "prompt>";
  std::vector<std::string> commandHistory;
  std::string currentCommand;
  int unremovable;
  bool localEchoEnabled;
};

#endif
