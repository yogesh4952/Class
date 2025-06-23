% Stop if everything is clean
agent_loop(State, _) :-
    all_clean(State),
    format('All squares are clean. Final state: ~w~n', [State]).

% Continue if not all clean
agent_loop(State, Location) :-
    perceive(State, Location, Cleanliness),
    ( Cleanliness = 1 ->
        suck(State, Location, NewState),
        format('Sucked dirt at location ~w. New state: ~w~n', [Location, NewState]),
        agent_loop(NewState, Location)
    ;
        format('Location ~w is clean.~n', [Location]),
        random(1, 3, Action),  % Random: 1 = move, 2 = stay
        ( Action = 1 ->
            move(Location, NewLocation),
            format('Moving to location ~w.~n', [NewLocation]),
            agent_loop(State, NewLocation)
        ;
            format('Staying at location ~w.~n', [Location]),
            agent_loop(State, Location)
        )
    ).
