import { useState, useEffect } from 'react';
import './index.css';

function App() {
  const [data, setData] = useState(null);
  const [selectedProblem, setSelectedProblem] = useState(null);
  const [expandedCategory, setExpandedCategory] = useState(null);
  const [searchQuery, setSearchQuery] = useState('');
  const [isSidebarOpen, setIsSidebarOpen] = useState(true);

  useEffect(() => {
    fetch('./data.json')
      .then(res => res.json())
      .then(d => {
        setData(d);
        if (d.categories.length > 0) {
          setExpandedCategory(d.categories[0].name);
        }
      });
  }, []);

  if (!data) return <div className="loading">Loading Dashboard...</div>;

  return (
    <div className="app-container">
      <header className="app-header">
        <div className="header-left">
          <button className="menu-btn" onClick={() => setIsSidebarOpen(!isSidebarOpen)}>☰</button>
          <h1 onClick={() => { setSelectedProblem(null); setIsSidebarOpen(true); }} style={{ cursor: 'pointer' }}>
            Neetcode 150 solutions
          </h1>
        </div>
        <div className="search-container">
          <input 
            type="text" 
            className="search-input" 
            placeholder="Search LC ID or Title..." 
            value={searchQuery}
            onChange={(e) => setSearchQuery(e.target.value)}
          />
          {searchQuery && (
            <div className="search-results">
              {Object.values(data.problems)
                .filter(p => p.id.includes(searchQuery) || p.title.toLowerCase().includes(searchQuery.toLowerCase()))
                .slice(0, 10)
                .map(p => (
                  <div key={p.id} className="search-result-item" onClick={() => {
                    setSelectedProblem(p);
                    setExpandedCategory(p.category);
                    setSearchQuery('');
                    setIsSidebarOpen(false);
                  }}>
                    <span className="status">{p.status_icon}</span>
                    <span>LC {p.id}: {p.title}</span>
                  </div>
                ))}
            </div>
          )}
        </div>
        <div className="stats">
          <span>{Object.values(data.problems).filter(p => p.is_solved).length} / {Object.keys(data.problems).length} Solved</span>
        </div>
      </header>

      <div className="main-content">
        {isSidebarOpen && (
          <aside className="sidebar">
            {data.categories.map(cat => (
              <div key={cat.name} className="category-group">
                <button 
                  className={`category-header ${expandedCategory === cat.name ? 'active' : ''}`}
                  onClick={() => setExpandedCategory(expandedCategory === cat.name ? null : cat.name)}
                >
                  <span className="arrow">{expandedCategory === cat.name ? '▼' : '▶'}</span>
                  {cat.name} ({cat.problems.filter(id => data.problems[id].is_solved).length}/{cat.problems.length})
                </button>
                
                {expandedCategory === cat.name && (
                  <div className="problem-list">
                    {cat.problems.map(probId => {
                      const prob = data.problems[probId];
                      return (
                        <div 
                          key={prob.id} 
                          className={`problem-item ${selectedProblem?.id === prob.id ? 'selected' : ''}`}
                          onClick={() => {
                            setSelectedProblem(prob);
                            setIsSidebarOpen(false); // auto-collapse
                          }}
                        >
                          <span className="status">{prob.status_icon}</span>
                          <span className="title">LC {prob.id}: {prob.title}</span>
                        </div>
                      );
                    })}
                  </div>
                )}
              </div>
            ))}
          </aside>
        )}

        <main className="content-panel">
          {selectedProblem ? (
            <div className="problem-details">
              <div className="problem-header">
                <h2>LC {selectedProblem.id}: {selectedProblem.title}</h2>
                <a href={selectedProblem.lc_url} target="_blank" rel="noreferrer" className="btn-leetcode">Solve on LeetCode</a>
              </div>

              {selectedProblem.description && (
                <div className="description-section">
                  <h3>Problem Description</h3>
                  <div className="description-content">
                    {selectedProblem.description.split('\n').map((line, i) => {
                      const trimmedLine = line.trim();
                      if (!trimmedLine) return null;
                      
                      if (trimmedLine.startsWith('Example') || trimmedLine.startsWith('Constraints:')) {
                        return <h4 key={i} className="desc-heading">{trimmedLine}</h4>;
                      }
                      if (trimmedLine.startsWith('Input:') || trimmedLine.startsWith('Output:') || trimmedLine.startsWith('Explanation:')) {
                        const parts = trimmedLine.split(':');
                        return (
                          <div key={i} className="desc-io">
                            <strong>{parts[0]}:</strong>{parts.slice(1).join(':')}
                          </div>
                        );
                      }
                      if (trimmedLine.startsWith('- ') || trimmedLine.startsWith('1 <= ') || trimmedLine.startsWith('0 <=')) {
                         return <li key={i} className="desc-list-item">{trimmedLine}</li>;
                      }
                      return <p key={i}>{trimmedLine}</p>;
                    })}
                  </div>
                </div>
              )}
              
              {selectedProblem.video_url && (
                <details className="collapsible-section">
                  <summary>View Video Solution</summary>
                  <div className="video-container">
                    <iframe 
                      src={selectedProblem.video_url} 
                      title="YouTube video player" 
                      allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
                      allowFullScreen
                    ></iframe>
                  </div>
                </details>
              )}

              <details className="collapsible-section">
                <summary>View C++ Source Code</summary>
                <div className="code-section">
                  {selectedProblem.code ? (
                    <pre className="code-block">
                      <code>{selectedProblem.code}</code>
                    </pre>
                  ) : (
                    <div className="no-code">Code not yet written.</div>
                  )}
                </div>
              </details>
            </div>
          ) : (
            <div className="home-table-container">
              <table className="home-table">
                <thead>
                  <tr>
                    <th style={{ width: '25%' }}>Category</th>
                    <th style={{ width: '75%' }}>Problems</th>
                  </tr>
                </thead>
                <tbody>
                  {data.categories.map(cat => (
                    <tr key={cat.name}>
                      <td className="category-cell">
                        <span className="cat-name">{cat.name}</span>
                        <div className="cat-stats">({cat.problems.filter(id => data.problems[id].is_solved).length}/{cat.problems.length} Solved)</div>
                      </td>
                      <td className="problems-cell">
                        {cat.problems.map(probId => {
                          const prob = data.problems[probId];
                          const diffClass = prob.difficulty ? prob.difficulty.toLowerCase() : 'medium';
                          return (
                            <div 
                              key={prob.id} 
                              className={`prob-badge ${prob.is_solved ? 'solved' : 'unsolved'}`}
                              onClick={() => {
                                setSelectedProblem(prob);
                                setExpandedCategory(prob.category);
                                setIsSidebarOpen(false);
                              }}
                            >
                              <span className="prob-id">{prob.id}</span>
                              <div className="tooltip-card">
                                <div className="tooltip-header">
                                  <strong>LC {prob.id}: {prob.title}</strong>
                                  <span className={`diff-tag ${diffClass}`}>{prob.difficulty || 'Medium'}</span>
                                </div>
                                <div className="tooltip-status">
                                  Status: {prob.is_solved ? <span style={{color: '#4ade80'}}>Solved 🟢</span> : <span style={{color: '#94a3b8'}}>Unsolved ⚪</span>}
                                </div>
                                <p className="tooltip-desc">{prob.description ? prob.description.substring(0, 120) + '...' : 'No description available.'}</p>
                              </div>
                            </div>
                          );
                        })}
                      </td>
                    </tr>
                  ))}
                </tbody>
              </table>
            </div>
          )}
        </main>
      </div>
    </div>
  );
}

export default App;

