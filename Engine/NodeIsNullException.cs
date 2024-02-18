namespace EightPuzzleGame.Engine {

    internal class NodeIsNullException : Exception {
        /// 
        /// <summary>
        /// Creeates a new Exception indicating that a given
        /// node is null.
        /// </summary>
        /// <param name="message">Error message to display</param>
        /// 
        public NodeIsNullException() : base() { }
    }
}
