namespace EightPuzzleGame.Utils {

    public class InvalidGameStateException : Exception {
        /// 
        /// <summary>
        /// Creeates a new Exception indicating that a given
        /// game state is not really a possible game state.
        /// </summary>
        /// <param name="message"> Error message to display </param>
        /// 
        public InvalidGameStateException(string message) : base(message) { }
    }
}
