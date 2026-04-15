# GigBuddy
> A simple project that turned into something more.

I started GigBuddy as a tool to solve a problem I hated dealing with 
every year — figuring out how much tax to withhold so the government 
doesn't get an interest-free loan at my expense. A simple W-4 optimizer 
to keep more of my paycheck on payday.

It was from that tool, and my side work as a freelance handyman, that I 
got the idea to build something bigger. Something that solves a problem 
many freelance and gig workers face: calculating taxes throughout the 
year, knowing how much is safe to spend, and how much to set aside for 
the IRS.

There are apps that solve this problem — many connect to your bank, many 
ship your data to cloud servers, many bundle in a host of conveniences 
you didn't ask for. GigBuddy takes a different approach.

**100% local. No internet required. Your data stays on your device.**

Users are never asked for SSNs, bank account details, or sensitive 
credentials. All data is stored locally in an encrypted SQLite database, 
persisted across sessions, and secured at rest. If you lose your device, 
your information stays protected.

---

## Architecture

| Layer | Technology | Purpose |
|---|---|---|
| UI | Flutter | Cross-platform mobile interface |
| Bridge | Dart FFI | Zero-overhead C++ interop |
| Backend | C++ | Tax calculation engine |
| Storage | SQLite (encrypted) | Local data persistence |
| Tax Data | JSON | Updatable bracket/rate definitions |

The calculation engine is deliberately decoupled from the UI — the C++ 
backend has no Flutter dependencies and can be tested independently or 
reused in other contexts.

---

## Features

**Income Tracking**
- Variable pay frequency support (per-stop, daily, weekly, monthly)
- Automatic annualization across mixed income types

**Tax Estimation**
- Self-employment tax calculation (Social Security + Medicare)
- Deduction modeling
- Effective rate breakdown

**Quarterly Planning**
- Per-quarter payment estimates
- W-4 optimizer for mixed W-2/1099 income

> ⚠️ Active development — not yet suitable for actual tax filing.

---

## Status

Backend calculation engine ~50% complete.

**Completed**
- [x] Basic W-4 marginal tax rate logic
- [x] Income annualization across pay frequencies
- [x] Tax bracket data via updatable JSON
- [x] Console-based UI for backend testing

**In Progress**
- [ ] Input validation helper (template-based, reusable)
- [ ] Self-employment tax calculation
- [ ] State tax calculation
- [ ] Quarterly payment estimates

**Planned**
- [ ] W-4 optimizer
- [ ] Encrypted local storage
- [ ] Flutter UI (wizard-style input flow)
- [ ] Login via username/password or biometrics
- [ ] User input via manual entry or document scan
- [ ] Automatic storage cleanup based on user preferences

---

## Building

## Building

### Backend (C++)
Currently developed and tested in Visual Studio 2026 on Windows.
CMake support for cross-platform mobile builds planned prior to 
Flutter integration.

### Flutter App
*Coming soon — Flutter UI in active planning.*
---

## About

Built by a former truck driver solving real problems while learning 
software engineering. GigBuddy exists because the tools that should 
exist for gig workers mostly don't — or they come with strings attached.
