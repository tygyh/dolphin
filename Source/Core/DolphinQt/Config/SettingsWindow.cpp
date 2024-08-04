// Copyright 2016 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "DolphinQt/Config/SettingsWindow.h"

#include <QDialogButtonBox>
#include <QTabWidget>
#include <QVBoxLayout>

#include "DolphinQt/QtUtils/WrapInScrollArea.h"
#include "DolphinQt/Settings.h"
#include "DolphinQt/Settings/AdvancedPane.h"
#include "DolphinQt/Settings/AudioPane.h"
#include "DolphinQt/Settings/GameCubePane.h"
#include "DolphinQt/Settings/GeneralPane.h"
#include "DolphinQt/Settings/InterfacePane.h"
#include "DolphinQt/Settings/PathPane.h"
#include "DolphinQt/Settings/WiiPane.h"

SettingsWindow::SettingsWindow(QWidget* parent) : QDialog(parent)
{
  // Set Window Properties
  setWindowTitle(tr("Settings"));
  setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

  // Main Layout
  auto layout = new QVBoxLayout;

  // Add content to layout before dialog buttons.
  m_tab_widget = new QTabWidget();
  layout->addWidget(m_tab_widget);

  m_tab_widget->addTab(GetWrappedWidget(new GeneralPane, this, 125, 100), tr("General"));
  m_tab_widget->addTab(GetWrappedWidget(new InterfacePane, this, 125, 100), tr("Interface"));
  m_tab_widget->addTab(GetWrappedWidget(new AudioPane, this, 125, 100), tr("Audio"));
  m_tab_widget->addTab(GetWrappedWidget(new PathPane, this, 125, 100), tr("Paths"));
  m_tab_widget->addTab(GetWrappedWidget(new GameCubePane, this, 125, 100), tr("GameCube"));
  m_tab_widget->addTab(GetWrappedWidget(new WiiPane, this, 125, 100), tr("Wii"));
  m_tab_widget->addTab(GetWrappedWidget(new AdvancedPane, this, 125, 200), tr("Advanced"));

  // Dialog box buttons
  auto close_box = new QDialogButtonBox(QDialogButtonBox::Close);

  connect(close_box, &QDialogButtonBox::rejected, this, &QDialog::reject);

  layout->addWidget(close_box);

  setLayout(layout);
}

void SettingsWindow::SelectAudioPane() const
{
  m_tab_widget->setCurrentIndex(static_cast<int>(TabIndex::Audio));
}

void SettingsWindow::SelectGeneralPane() const
{
  m_tab_widget->setCurrentIndex(static_cast<int>(TabIndex::General));
}
