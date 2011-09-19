/*
    This file is part of open-pdf-presenter.

    open-pdf-presenter is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    open-pdf-presenter is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with open-pdf-presenter.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "console.h"

#include <iostream>
#include <QLabel>
#include <QPushButton>

PresenterConsoleViewImpl::PresenterConsoleViewImpl(QWidget * parent) : QWidget(parent) {
	this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	this->layout = new QVBoxLayout(this);
  this->layout->setSpacing(0);
  this->layout->setMargin(0);
	this->setLayout(this->layout);

  this->mainWidget = new QWidget();
  this->layout->addWidget(this->mainWidget);

  this->barWidget= new QWidget();
  this->layout->addWidget(this->barWidget);

}

void PresenterConsoleViewImpl::setController(PresenterConsoleViewController * controller) {
}

void PresenterConsoleViewImpl::setControlBarView(ControlBarView * view) {

  this->layout->removeWidget(this->mainWidget);
  this->layout->removeWidget(this->barWidget);


	view->asWidget()->setParent(this);
  this->barWidget = view->asWidget();

  this->layout->addWidget(this->mainWidget);
  this->layout->addWidget(this->barWidget);
	this->layout->setAlignment(this->barWidget,Qt::AlignHCenter | Qt::AlignBottom);
}

QWidget * PresenterConsoleViewImpl::asWidget() {
	return this;
}

SlideFrame::SlideFrame(QWidget * parent) : QWidget(parent) {
	ui.setupUi(this);
}

void SlideFrame::setContent(QWidget * content) {
	this->ui.contentLayout->addWidget(content);
}
