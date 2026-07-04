# Algorithmic Trading Backtester - Development Workflow

This document establishes the development lifecycle, task distribution, and tooling for the team consisting of 1 Medior and 2 Junior developers.

## 1. Team Topology & Responsibilities

### 1.1 Technical Lead
- **Architecture & Infrastructure**: Sets up the core Qt application structure, base classes, and thread management.
- **CI/CD & DevOps**: Manages the GitHub repository and maintains GitHub Actions pipelines for automated builds and testing.
- **Code Review**: Approves Pull Requests, ensuring code quality and architectural consistency.
- **Core Engine**: Implements the initial Backtesting Engine loop and basic fill logic.

### 1.2 Developers
- **Data Integrations**: Implements API clients (Tiingo, Alpha Vantage, etc.) and `rapidcsv` parsers based on interfaces defined.
- **UI & Visualization**: Builds the GUI Strategy Builder and integrates `QCustomPlot` charting.
- **Indicators**: Implements mathematical logic for various technical indicators used in the GUI builder.

## 2. Agentic Tooling & Knowledge Management

### 2.1 The "Knowledge Graph" Strategy
Agentic tools are most effective when they understand the broader context of the project.
- **Module Documentation**: Each module (Data, Engine, UI) will maintain a high-level `README.md` or architectural outline (like this document). 
- **Context Injection**: Developers should use tools that maintain a "knowledge graph" of the repository. By having clear, up-to-date documentation on how modules interact (e.g., standard internal Data structures, Signal/Slot event flows), AI tools can easily retrieve context and generate accurate, project-specific code snippets.
- **Learning & Onboarding**: Team members can query their agentic tools (e.g., "Explain how the Data Acquisition thread signals the UI based on our architecture docs") to get up to speed quickly without blocking each other.

## 3. Development Lifecycle

### 3.1 Version Control (GitHub)
- **Main Branch**: The `master` branch must always compile and pass tests.
- **Feature Branches**: Developers create branches (e.g., `feature/tiingo-api`, `feature/gui-builder`) for their work.

### 3.2 CI/CD (GitHub Actions)
- On every push and Pull Request, GitHub Actions will:
  1. Compile the C++ project using CMake.
  2. Run automated unit tests with QtTest.
  3. Perform basic static analysis.

### 3.3 Pull Request Process
- **Minimal Feature Sets**: PRs should be small and focused on a minimal feature set (as defined in our feature plan) to ensure quick review cycles.
- **Review**: At least one other team member must review and approve PRs. The focus will be on ensuring Qt threading rules (Signal/Slot boundaries) and memory safety are respected.
