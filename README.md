GigBuddy - A simple project that turned into something more.

I started GigBuddy as a simple tool to solve a little problem that I hated dealing with every year. Figuring out how much tax I should have taken out of my check to ensure the government doesn't receive an interest-free loan.
A simple W-4 optimizer to ensure I kept most of my paycheck on payday.
It was from this simple tool, and my side gig as a freelance handyman, that I got the idea to create something even bigger. Something that solves a problem that many freelance and gig workers face, calculating their taxes throughout the year, knowing how much they have
to spend, and how much to put aside for the IRS. 
Sure, there are apps out there that solve this problem; many of them allow users to connect their bank accounts, and many of them ship your information to far-off cloud servers for storage. As well as a host of other conveniences.
What I wanted GigBuddy to be was something that was 100% localized, efficient, and usable when internet services are not available. 
To do this, I decided that the entire app was to be localized and security based. While users are not required to provide SSNs, bank account details, or any other sensitive information to GigBuddy, security and control of their information, regardless of what it is, should belong to the user.
Not some third-party banking API or cloud provider. To do this, all information will be stored on the users device, in a localized database utilizing SQLite. Information will be encrypted at rest and persist throughout sessions. 
What this means is that even if the user loses their device, their information will be secured.


##Architecture

|   layer   |        tech        |          purpose                    |
|     UI    |  Flutter           | Cross-Platform mobile Interface     |
|   Bridge  |  Dart FFI          | Zero-overhead c++ intop             |
|  Backend  |  C++               | Tax Calculation Engine              |
|  Storage  |  SQLite(encrypted) | Local Data Persistence              |
|  Tax Data |  JSON              | Updatable bracket/rate definitions  |

The calculation engine is deliberately decoupled from the UI - The backend has no Flutter dependencies and can be tested independently or reused in other contexts.

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


> ⚠️ Active development  
 ## Status

Currently in active development. Backend calculation engine 
~50% complete. Not yet suitable for actual tax filing.

### Completed
- [x] Basic W4 marginal tax rate logic
- [x] Console-based UI (for testing)
- [x] Income annualization across pay frequencies
- [x] Tax data available via updatable JSON file
- [x] many other things. 

### In Progress
- [ ] Input validation helper (template-based, reusable)
- [ ] Self-employment tax calculation
- [ ] State Tax calculator 
- [ ] Quarterly payment estimates

### Planned
- [ ] W-4 optimizer
- [ ] Encrypted local storage
- [ ] Flutter UI (wizard-style input flow)
- [ ] login via username/password or biometrics
- [ ] user input via manual entry or document scan
- [ ] automatic storage cleanup based on user preferences.
      
