# GPIO
Simple GPIO implementation over Network.

## API Structure
### Setter:

| Command            | Address    | Value |
|--------------------|------------|-------|
| WA (Write Analog)  | eq. GPIO10 | 1.0   |
| WD (Write Digital) | eq. GPIO10 | true  |


### Getter:

| Command           | Address    |
|-------------------|------------|
| RA (Read Analog)  | eq. GPIO10 |
| RD (Read Digital) | eq. GPIO10 |