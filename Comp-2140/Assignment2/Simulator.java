public class Simulator {
     public static boolean run (DFA dfa, String input) {
          String currentState = dfa.startState;
          
          for (int i = 0; i < input.length(); i++) {
               currentState = dfa.transitions.get(currentState + "_" + input.charAt(i));
          }

          if (dfa.finalStates.contains(currentState)) {
               return true;
          } else {
               return false;
          }
     }
}