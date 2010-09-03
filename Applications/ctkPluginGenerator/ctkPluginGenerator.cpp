/*=============================================================================

  Library: CTK

  Copyright (c) 2010 German Cancer Research Center,
    Division of Medical and Biological Informatics

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=============================================================================*/

#include "ctkPluginGenerator.h"
#include "ui_ctkPluginGeneratorMainWindow.h"

#include <ctkPluginFramework.h>


ctkPluginGenerator::ctkPluginGenerator(ctkPluginFramework* framework, QWidget *parent) :
    QMainWindow(parent),
    framework(framework), ui(new Ui::ctkPluginGeneratorMainWindow),
    mode(EDIT)
{
    ui->setupUi(this);

    this->setStatusBar(0);

    connect(ui->previewButton, SIGNAL(clicked()), this, SLOT(previewClicked()));
    connect(ui->cancelButton, SIGNAL(clicked()), qApp, SLOT(quit()));


}

ctkPluginGenerator::~ctkPluginGenerator()
{
    delete ui;
}

void ctkPluginGenerator::sectionErrorMessage(const QString& errorMsg)
{
  ui->sectionMessageLabel->setText(errorMsg);
}

void ctkPluginGenerator::previewClicked()
{
  if (mode == EDIT)
  {
    ui->modeStack->setCurrentWidget(ui->previewPage);
    ui->previewButton->setText(tr("<< Back"));
    mode = PREVIEW;
  }
  else
  {
    ui->modeStack->setCurrentWidget(ui->editPage);
    ui->previewButton->setText(tr("Preview >>"));
    mode = EDIT;
  }
}
