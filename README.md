# Uniplex_LE
Lightweight version of Uniplex system

"Uniplex LE" ist ein Github-Repository, das eine Firmware für die Plattform mit einem STM32-Mikrocontroller enthält.
Die Firmware ermöglicht die Steuerung und Integration verschiedener Komponenten wie TFT-Touchscreen-Display, RTC, USB- und NFC-Schnittstellen, Bluetooth-Kommunikation sowie Temperatur- und Feuchtigkeitssensoren.
Das Hauptziel des Projekts ist es, eine energieeffiziente Lösung mit niedrigem Stromverbrauch zu entwickeln, was besonders für batteriebetriebene Anwendungen von Vorteil ist.

## Inhaltsverzeichnis

- [Beschreibung](#beschreibung)
- [Features](#features)
- [Installation](#installation)
- [Verwendung](#verwendung)
- [Beitragende](#beitragende)
- [Lizenz](#lizenz)

## Beschreibung

Dieses Repository enthält die Firmware für eine Plattform, die auf einem STM32-Mikrocontroller basiert. Die Firmware ist in C geschrieben und ermöglicht die Steuerung verschiedener Komponenten, darunter:

- TFT-Display mit Touchscreen: Das TFT-Display mit Touchscreen ermöglicht die allgemeine Steuerung der Benutzeroberfläche und die Anzeige von Messwerten. Durch die Berührung des Displays können Benutzerinteraktionen durchgeführt werden.

- RTC (Echtzeituhr): Die RTC stellt die aktuelle Zeit für das System bereit. Sie ermöglicht die Zeitsynchronisation und die Verwendung von Zeitstempeln für verschiedene Anwendungen innerhalb der Plattform.

- USB-Schnittstelle: Die USB-Schnittstelle dient als allgemeine Kommunikationsschnittstelle für das System. Zusätzlich fungiert sie als Ladeanschluss für die Batterie, sodass die Plattform über USB aufgeladen werden kann.

- NFC-Schnittstelle: Die NFC-Schnittstelle ermöglicht die Verbindung der Bluetooth-Schnittstelle mit NDEF (NFC Data Exchange Format). Dadurch können Daten zwischen der Plattform und anderen NFC-fähigen Geräten drahtlos ausgetauscht werden.

- Bluetooth: Die Bluetooth-Funktion ermöglicht eine schnelle drahtlose Kommunikation mit anderen Bluetooth-fähigen Geräten. Dies eröffnet Möglichkeiten für die Datenübertragung, Fernsteuerung und drahtlose Konnektivität zu anderen Systemen.

- Temperatur- und Feuchtigkeitssensoren: Zwei Sensoren werden verwendet, um präzise Temperatur- und Feuchtigkeitsmessungen durchzuführen. Die Daten können für Überwachungszwecke oder zur Steuerung anderer Systemkomponenten verwendet werden.

- Flash-Speicher: Der Flash-Speicher dient zur Speicherung von Daten und Programmcodes.

- Batterieüberwachung: Die Batterieüberwachungsfunktion ermöglicht die Überwachung des Batteriestatus und die Erfassung wichtiger Parameter wie Spannung und Ladestand, um eine effiziente Nutzung der Batterie zu gewährleisten.

Das Hauptziel dieser Schaltung ist es, einen möglichst geringen Stromverbrauch zu erreichen. Durch die Implementierung von Stromsparmechanismen und Optimierungen wird die Energieeffizienz maximiert, was insbesondere für batteriebetriebene Anwendungen von Vorteil ist.


## Features

Liste hier die Hauptfeatures oder Funktionen deines Projekts auf. Dies ermöglicht es anderen Benutzern, schnell zu verstehen, was dein Projekt kann.

## Installation

Beschreibe hier die Schritte, die erforderlich sind, um dein Projekt lokal zum Laufen zu bringen. Dies beinhaltet normalerweise das Klonen des Repositories, die Installation von Abhängigkeiten und die Konfiguration von Umgebungsvariablen.

```bash
$ git clone https://github.com/DeinBenutzername/DeinRepository.git
$ cd DeinRepository
$ npm install  # oder die entsprechenden Befehle für deine Sprache/Umgebung

