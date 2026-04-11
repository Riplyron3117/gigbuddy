# Copilot Instructions

## Project Guidelines
- User aims to architect input handling so only UI adapters change (console cin/prompt to Flutter input/text), by consolidating input collection and isolating loop logic in a template-based helper.
- User prefers to refactor existing InputCollector instead of adding a new class now, limiting it to prompt/std::cin adapter responsibilities while a shared helper handles loop logic. 
- User prefers architecture where input collection is isolated as a UI adapter layer handling only raw input (currently std::cin), with helper-driven loop logic and reusable validation for future Flutter UI migration.
- User confirms preferred control flow: InputCollector function calls shared helper; helper invokes reader callback for prompt/input each iteration; helper runs validation and loops until valid.