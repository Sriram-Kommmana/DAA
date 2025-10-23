# Dinic's Algorithm for Maximum Flow

This repository contains a C++ implementation of **Dinic's Algorithm**, a fast and efficient algorithm to compute the **maximum flow** in a flow network.

---

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [How It Works](#how-it-works)
- [Usage](#usage)
- [Example](#example)
- [Input Format](#input-format)
- [Output](#output)
- [References](#references)

---

## Overview

Dinic's Algorithm is a **network flow algorithm** that finds the maximum flow in a graph using **level graphs** and **blocking flows**. It is more efficient than the Ford-Fulkerson method in networks with multiple paths.

- **Time Complexity:** O(V² * E) for general graphs, O(E * sqrt(V)) for unit networks.
- **Space Complexity:** O(V + E)

---

## Features

- Supports directed graphs with integer capacities.
- Uses BFS to construct a level graph.
- Uses DFS to send blocking flows.
- Efficient and easy-to-understand implementation.

---

## How It Works

1. **Level Graph Construction (BFS):**
   - Perform BFS from the source node.
   - Assign levels to all reachable nodes using only edges with remaining capacity.

2. **Blocking Flow (DFS):**
   - Send flow along paths from source to sink respecting the level graph.
   - Update residual capacities.
   - Repeat until no more blocking flows exist.

3. **Repeat:**
   - Rebuild the level graph and repeat DFS until the sink is unreachable.

---

## Usage

1. **Compile the program:**
```bash
g++ -std=c++17 -o dinic dinic.cpp
