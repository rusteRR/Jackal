Формат JSON получения состояния игры

```json
{
  "game": "Jackal",
  "response_type": "game_state",
  "current_player": int,
  "players_data": [
    {
      "player_id": int,
      "total_coins": int,
      "pirates": [
        {
          "pirate_id": int,
          "coord_x": int,
          "coord_y": int,
          "coins_amount": int,
          "is_dead": bool
        }
      ],
      "ship_coord_x": int,
      "ship_coord_y": int,
    }
  ],
  "field_data": [
    {
      "coord_x": int,
      "coord_y": int,
      "is_open": bool,
      "filename": string,
      "coins": int
    }
  ]
}
```